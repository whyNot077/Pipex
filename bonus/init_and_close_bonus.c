/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:52:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 22:08:28 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	write_to_pipe_for_here_doc(int fd, const char *limiter)
{
	char	*line;

	line = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strcmp(line, limiter) == EQUAL)
		{
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) == -1)
		{
			free(line);
			perror_return("Failed to write to pipe for here_doc", 1);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
	exit(0);
}

static void	init_heardoc(t_args *args, t_pipe *t_pipe)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (pipe(pipe_fds) == -1)
		perror_return("Failed to create pipe for here_doc", 1);
	pid = fork();
	if (pid < 0)
		perror_return("Failed to fork for here_doc", 1);
	else if (pid == 0)
	{
		close(pipe_fds[0]);
		write_to_pipe_for_here_doc(pipe_fds[1], args->limiter);
	}
	else
	{
		close(pipe_fds[1]);
		t_pipe->input_fd = pipe_fds[0];
		t_pipe->pid[0] = pid;
	}
}

static void	args_to_pipe(t_args *args, t_pipe *pipe)
{
	int		*pipes;

	pipe->input_fd = -1;
	pipe->output_fd = -1;
	pipe->num_commands = args->num_commands;
	pipe->commands = args->commands;
	pipe->here_doc = args->here_doc;
	pipe->limiter = args->limiter;
	pipes = (int *)malloc(sizeof(int) * (args->num_commands - 1) * 2);
	if (!pipes)
		perror_return("Failed to allocate memory for pipes", 1);
	pipe->pipes = pipes;
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * args->num_commands);
	if (!pipe->pid)
		perror_return("Failed to allocate memory for PIDs", 1);
}

t_pipe	*init_pipe(t_args *args)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof(t_pipe));
	if (!pipe)
		perror_return("Failed to allocate memory for pipe", 1);
	args_to_pipe(args, pipe);
	if (args->here_doc)
		init_heardoc(args, pipe);
	else
	{
		pipe->input_fd = open(args->input_file, O_RDONLY);
		if (pipe->input_fd < 0)
			perror_return("Failed to open input file", 1);
	}
	pipe->output_fd = \
		open(args->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe->output_fd < 0)
		perror_return("Failed to open output file", 1);
	return (pipe);
}

void	close_parent(t_pipe *pipe)
{
	int	i;
	int	num_pipes;

	close(pipe->input_fd);
	close(pipe->output_fd);
	num_pipes = (pipe->num_commands - 1) * 2;
	i = 0;
	while (i < num_pipes)
	{
		close(pipe->pipes[i]);
		i++;
	}
}
