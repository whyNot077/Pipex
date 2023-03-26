/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_pipes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:48:07 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/26 18:24:22 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static void	dup2_and_check(int old_fd, int new_fd, const char *error_message)
{
	if (dup2(old_fd, new_fd) == -1)
		perror_return(error_message, 1);
}

static void	link_receive_pipes(t_pipe *pipe, int index)
{
	if (index == 0)
	{
		open_in_file(pipe);
		dup2_and_check(pipe->input_fd, STDIN_FILENO, \
			"Failed to duplicate pipe read end");
	}
	else
	{
		dup2_and_check(pipe->pipes[index - 1][0], STDIN_FILENO, \
			"Failed to duplicate pipe read end");
	}
}

static void	link_give_pipes(t_pipe *pipe, int index, int num_commands)
{
	if (index == num_commands - 1)
	{
		open_out_file(pipe);
		dup2_and_check(pipe->output_fd, STDOUT_FILENO, \
			"Error duplicating file descriptor");
	}
	else
	{
		dup2_and_check(pipe->pipes[index][1], STDOUT_FILENO, \
			"Failed to duplicate pipe write end");
	}
}

static void	close_all_pipes(t_pipe *pipe, int num_commands)
{
	int	j;

	j = 0;
	while (j < num_commands - 1)
	{
		close(pipe->pipes[j][0]);
		close(pipe->pipes[j][1]);
		j++;
	}
}

void	link_pipes(t_pipe *pipe, int index, int num_commands)
{
	link_receive_pipes(pipe, index);
	link_give_pipes(pipe, index, num_commands);
	close_all_pipes(pipe, num_commands);
}
