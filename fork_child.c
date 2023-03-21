/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:36:08 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/21 21:37:17 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_command(const char *command)
{
	char	**command_and_options;

	command_and_options = ft_split(command, ' ');
	return (command_and_options);
}

void	fork_child_one(t_pipe *pipe, \
	const char *first_command, char *envp[])
{
	char	*path;
	char	**argv;

	argv = get_command(first_command);
	path = get_accessible_path(pipe->path, argv[0]);
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
		execve(path, argv, envp);
		perror_return("Error executing command 1", 1);
	}
}

void	fork_child_two(t_pipe *pipe, \
	const char *second_command, char *envp[])
{
	char	*path;
	char	**argv;

	argv = get_command(second_command);
	path = get_accessible_path(pipe->path, argv[0]);
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
		execve(path, argv, envp);
		perror_return("Error executing command 2", 1);
	}
}
