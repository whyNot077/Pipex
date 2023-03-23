/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:30:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/23 13:34:07 by minkim3          ###   ########.fr       */
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
		close(pipe->pipes[i]);
		i++;
	}
}

static void	free_pipe(t_pipe *pipe)
{
	free_two_dementional_array(pipe->path);
	free(pipe);
}


void	close_pipe(t_pipe *pipe, t_args *args)
{
	int	i;

	close_parent(pipe);
	i = 0;
	while (i < args->num_commands)
	{
		wait(NULL);
		i++;
	}
	free_pipe(pipe);
	free(args);
}