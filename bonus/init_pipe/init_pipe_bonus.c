/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:10:19 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/26 14:47:27 by minjukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static int	heardoc_has_no_command(t_pipe *pipe)
{
	if (pipe->here_doc == false || pipe->num_commands > 0)
		return (FALSE);
	pipe->pipes = NULL;
	pipe->pid = NULL;
	return (TRUE);
}

void	init_pipe(t_pipe *pipe)
{
	pipe->input_fd = -1;
	pipe->output_fd = -1;
	if (heardoc_has_no_command(pipe) == TRUE)
		return ;
	pipe->pipes = (int **)malloc(sizeof(int *) * (pipe->num_commands - 1));
	if (!pipe->pipes)
		perror_return("Failed to allocate memory for pipes", 1);
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * pipe->num_commands);
	if (!pipe->pid)
		perror_return("Failed to allocate memory for PIDs", 1);
}
