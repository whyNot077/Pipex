/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:30:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/24 14:45:29 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_parent(t_pipe *pipe)
{
	int	i;
	int	num_pipes;

	close(pipe->input_fd);
	close(pipe->output_fd);
	num_pipes = (pipe->num_commands - 1) * 2;
	i = 0;
	while (i < num_pipes)
	{
		close(pipe->pipe_fd[i]);
		i++;
	}
}

static void	free_pipe(t_pipe *pipe)
{
	free_two_dementional_array(pipe->path);
	free(pipe->commands);
	free(pipe->pipe_fd);
	free(pipe->limiter);
	free(pipe->pid);
	free(pipe);
}

static void	wait_for_child_process(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (i < pipe->num_commands)
	{
		wait(NULL);
		i++;
	}
}

void	close_pipe(t_pipe *pipe)
{
	close_parent(pipe);
	wait_for_child_process(pipe);
	free_pipe(pipe);
}
