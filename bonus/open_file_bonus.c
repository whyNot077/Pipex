/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:52:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/23 17:57:04 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	write_to_pipe_for_here_doc(int fd, const char *limiter)
{
	char	*line;

	line = NULL;
	line = get_next_line(STDIN_FILENO);
	ft_printf("%s\n", limiter);
	while (line)
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

static void	start_get_line(t_pipe *t_pipe)
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
		write_to_pipe_for_here_doc(pipe_fds[1], t_pipe->limiter);
	}
	else
	{
		close(pipe_fds[1]);
		t_pipe->input_fd = pipe_fds[0];
		t_pipe->pid[0] = pid;
	}
}

static void	init_pipe(t_pipe *pipe)
{
	pipe->input_fd = -1;
	pipe->output_fd = -1;
	pipe->pipes = (int *)malloc(sizeof(int) * (pipe->num_commands - 1) * 2);
	if (!pipe->pipes)
		perror_return("Failed to allocate memory for pipes", 1);
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * pipe->num_commands);
	if (!pipe->pid)
		perror_return("Failed to allocate memory for PIDs", 1);
}

void	open_file(t_pipe *pipe)
{
	init_pipe(pipe);
	if (pipe->here_doc)
		start_get_line(pipe);
	else
	{
		pipe->input_fd = open(pipe->input_file, O_RDONLY);
		if (pipe->input_fd < 0)
			perror_return("Failed to open input file", 1);
	}
	pipe->output_fd = \
		open(pipe->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe->output_fd < 0)
		perror_return("Failed to open output file", 1);
}
