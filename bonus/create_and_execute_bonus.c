/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_execute_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:36:08 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/24 16:36:49 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	create_pipes(t_pipe *t_pipe, int index)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		perror_return("Failed to create pipe", 1);
	t_pipe->pipes[index] = malloc(2 * sizeof(int));
	if (t_pipe->pipes[index] == NULL)
		perror_return("Failed to allocate memory for pipes", 1);
	t_pipe->pipes[index][0] = pipe_fds[0];
	t_pipe->pipes[index][1] = pipe_fds[1];
}

void	create_pipes_and_execute(t_pipe *pipe, char *envp[])
{
	int		index;
	int		num_commands;

	index = 0;
	num_commands = pipe->num_commands;
	while (index < num_commands - 1)
	{
		create_pipes(pipe, index);
		index++;
	}
	index = 0;
	while (index < num_commands)
	{
		execute_pipeline(pipe, index, envp);
		index++;
	}
}
