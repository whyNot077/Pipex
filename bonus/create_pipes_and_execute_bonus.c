/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes_and_execute_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:36:08 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 20:59:59 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	create_pipes(int *pipes, int num_commands)
{
	int	i;

	i = 0;
	while (i < num_commands - 1)
	{
		if (pipe(pipes + i * 2) == -1)
			perror_return("Failed to create pipe", 1);
		i++;
	}
}

void	create_pipes_and_execute(t_pipe *pipe, t_args *args, char *envp[])
{
	int		index;
	int		num_commands;
	int		*pipes;

	index = 0;
	num_commands = args->num_commands;
	pipes = (int *)malloc(sizeof(int) * (num_commands - 1) * 2);
	if (!pipes)
		perror_return("Failed to allocate memory for pipes", 1);
	create_pipes(pipes, num_commands);
	pipe->pipes = pipes;
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * num_commands);
	if (!pipe->pid)
		perror_return("Failed to allocate memory for PIDs", 1);
	while (index < num_commands)
	{
		execute_pipeline(pipe, args, index, envp);
		index++;
	}
}
