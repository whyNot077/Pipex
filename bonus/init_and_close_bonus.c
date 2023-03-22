/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:52:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 16:34:57 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_heardoc(t_args *args, t_pipe *pipe)
{
	int		pipe_fds[2];
	char	*line;
	ssize_t	read;

	line = NULL;
	if (pipe2(pipe_fds, O_CLOEXEC) == -1)
		perror_return("Failed to create pipe for here_doc", 1);
	read = getline(&line, NULL, stdin);
	while (read != -1)
	{
		if (strcmp(line, args->limiter) == 0)
			break ;
		write(pipe_fds[1], line, read);
		read = getline(&line, NULL, stdin);
	}
	close(pipe_fds[1]);
	pipe->input_fd = pipe_fds[0];
	if (line)
		free(line);
}

static void	args_to_pipe(t_args *args, t_pipe *pipe)
{
	pipe->num_commands = args->num_commands;
	pipe->commands = args->commands;
	pipe->here_doc = args->here_doc;
	pipe->limiter = args->limiter;
}

void	init_pipe(t_args *args, t_pipe *pipe)
{
	pipe->input_fd = -1;
	pipe->output_fd = -1;
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
	args_to_pipe(args, pipe);
}

void	close_parent(t_pipe *pipe)
{
	close(pipe->input_fd);
	close(pipe->output_fd);
	close(pipe->pipe_fd[0]);
	close(pipe->pipe_fd[1]);
}

void	free_pipe(t_pipe *pipe)
{
	free_two_dementional_array(pipe->path);
	free(pipe);
}
