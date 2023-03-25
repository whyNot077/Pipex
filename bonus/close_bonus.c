/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:30:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/25 20:31:24 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_parent(t_pipe *pipe)
{
	int	i;

	close(pipe->input_fd);
	close(pipe->output_fd);
	i = 0;
	while (pipe->num_commands && i < pipe->num_commands - 1)
	{
		close(pipe->pipes[i][0]);
		close(pipe->pipes[i][1]);
		i++;
	}
}

static void	free_pipe(t_pipe *pipe)
{
	int	index;

	index = 0;
	while (pipe->num_commands && index < pipe->num_commands - 1)
	{
		free(pipe->pipes[index]);
		index++;
	}
	free_two_dementional_array(pipe->path);
	free(pipe->commands);
	if (pipe->num_commands != 0)
	{
		free(pipe->pipes);
		free(pipe->pid);
	}
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
