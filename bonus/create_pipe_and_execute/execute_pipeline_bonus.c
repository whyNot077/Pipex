/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:53:25 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/26 18:47:32 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static char	**split_command_options(const char *command)
{
	char	**command_and_options;

	command_and_options = ft_split(command, ' ');
	return (command_and_options);
}

static void	execute_command(t_pipe *pipe, int i, char *envp[])
{
	char	*cmd_path;
	char	**command_and_options;

	command_and_options = split_command_options(pipe->commands[i]);
	if (access(pipe->commands[i], F_OK) == SUCCESS)
		cmd_path = ft_strdup(pipe->commands[i]);
	else
		cmd_path = get_accessible_path(pipe->path, command_and_options[0]);
	execve(cmd_path, command_and_options, envp);
	perror_return("Failed to execute command", 1);
}

void	execute_pipeline(t_pipe *pipe, int index, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_return("Failed to fork child process", 1);
	else if (pid == 0)
	{
		link_pipes(pipe, index, pipe->num_commands);
		execute_command(pipe, index, envp);
	}
	else
		pipe->pid[index] = pid;
}
