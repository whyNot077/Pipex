/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:06:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/23 22:10:17 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	write_to_pipe_for_here_doc(int fd, const char *limiter)
{
	char	*line;

	line = NULL;
	line = get_next_line(STDIN_FILENO);
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

static void	open_out_file(t_pipe *pipe)
{
	pipe->output_fd = \
		open(pipe->output_file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (pipe->output_fd < 0)
		perror_return("Failed to open output file", 1);
}

void	hear_doc(t_pipe *t_pipe)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (t_pipe->here_doc == false)
		return ;
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
	open_out_file(t_pipe);
}
