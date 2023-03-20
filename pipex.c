/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/20 16:16:24 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *find_path(char *envp[])
{
    char	*path_key;
    size_t	path_key_len;
    char	*path;
	int		i;

	path_key = "PATH=";
	path_key_len = ft_strlen(path_key);
	path = NULL;
    i = 0;
	while (envp[i] != NULL)
    {
        if (ft_strncmp(envp[i], path_key, path_key_len) == 0)
        {
            path = envp[i] + path_key_len;
            break;
        }
        i++;
    }
    if (path == NULL)
        perror_return("PATH environment variable not found", 1);
    return (path);
}

static void get_path(t_pipe *pipe, char *envp[])
{
	char	*path_value;
	char	*path;
	char	*sh_path;

	path_value = find_path(envp);
    path = ft_strtok(&path_value, ":");
    while (path != NULL)
    {
        sh_path = malloc(ft_strlen(path) + ft_strlen("/sh") + 1);
        ft_strlcpy(sh_path, path, ft_strlen(path) + ft_strlen("/sh") + 1);
        ft_strlcat(sh_path, "/sh", ft_strlen(path) + ft_strlen("/sh") + 1);
        if (access(sh_path, X_OK) == SUCCESS)
        {
            pipe->path = sh_path;
            break;
        }
        free(sh_path);
        path = ft_strtok(&path_value, ":");
    }
    if (pipe->path == NULL)
        perror_return("Could not find the shell path", 1);
}

static t_pipe	*init_pipe(const char *input_file, const char *output_file)
{
	t_pipe	*init_pipe;

	init_pipe = calloc(1, sizeof(t_pipe));
	init_pipe->input_fd = open(input_file, O_RDONLY);
	if (init_pipe->input_fd == ERROR)
		perror_return("Error opening input file", 1);
	init_pipe->output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (init_pipe->output_fd == ERROR)
		perror_return("Error opening output file", 1);
	if (pipe(init_pipe->pipe_fd) == ERROR)
		perror_return("Error creating pipe", 1);
	return (init_pipe);
}

static void	fork_child_one(t_pipe *pipe, \
	const char *command1_with_args, char *envp[])
{
	char *const	argv[] = {"sh", "-c", (char *)command1_with_args, NULL};

	pipe->pid_one = fork();
	if (pipe->pid_one == ERROR)
		perror_return("Error forking", 1);
	if (pipe->pid_one == 0)
	{
		if (dup2(pipe->input_fd, STDIN_FILENO) == -1)
			perror_return("Error duplicating file descriptor", 1);
		if (dup2(pipe->pipe_fd[1], STDOUT_FILENO) == -1)
			perror_return("Error duplicating file descriptor", 1);
		close(pipe->pipe_fd[0]);
		execve(pipe->path, argv, envp);
		perror_return("Error executing command 1", 1);
	}
}

static void	fork_child_two(t_pipe *pipe, \
	const char *command2_with_args, char *envp[])
{
	char *const	argv[] = {"sh", "-c", (char *)command2_with_args, NULL};

	pipe->pid_two = fork();
	if (pipe->pid_two == ERROR)
		perror_return("Error forking", 1);
	if (pipe->pid_two == 0)
	{
		if (dup2(pipe->pipe_fd[0], STDIN_FILENO) == -1)
			perror_return("Error duplicating file descriptor", 1);
		if (dup2(pipe->output_fd, STDOUT_FILENO) == -1)
			perror_return("Error duplicating file descriptor", 1);
		close(pipe->pipe_fd[1]);
		execve(pipe->path, argv, envp);
		perror_return("Error executing command 2", 1);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
	char	*input_file;
	char	*command1_with_args;
	char	*command2_with_args;
	char	*output_file;

	if (argc != 5)
		perror_return("Incorrect number of arguments", 1);
	input_file = argv[1];
	command1_with_args = argv[2];
	command2_with_args = argv[3];
	output_file = argv[4];
	pipe = init_pipe(input_file, output_file);
	get_path(pipe, envp);
	ft_printf("path = %s\n", pipe->path);
	fork_child_one(pipe, command1_with_args, envp);
	fork_child_two(pipe, command2_with_args, envp);
	waitpid(pipe->pid_one, NULL, 0);
	waitpid(pipe->pid_two, NULL, 0);
	free(pipe);
	return (0);
}
