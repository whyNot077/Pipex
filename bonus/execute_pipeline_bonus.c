/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:53:25 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 21:00:04 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	dup2_and_check(int old_fd, int new_fd, const char *error_message)
{
	if (dup2(old_fd, new_fd) == -1)
		perror_return(error_message, 1);
}

static void	setup_and_close_child_pipes(t_pipe *pipe, \
	int index, int num_commands)
{
	int	j;

	j = 0;
	if (index == 0)
		dup2_and_check(pipe->input_fd, STDIN_FILENO, \
			"Failed to duplicate pipe read end");
	if (index != 0)
		dup2_and_check(pipe->pipes[(index - 1) * 2], STDIN_FILENO, \
			"Failed to duplicate pipe read end");
	if (index != num_commands - 1)
		dup2_and_check(pipe->pipes[index * 2 + 1], STDOUT_FILENO, \
			"Failed to duplicate pipe write end");
	if (index == num_commands - 1)
		dup2_and_check(pipe->output_fd, STDOUT_FILENO, \
			"Error duplicating file descriptor");
	while (j < (num_commands - 1) * 2)
	{
		close(pipe->pipes[j]);
		j++;
	}
}

static char	**split_command_options(const char *command)
{
	char	**command_and_options;

	command_and_options = ft_split(command, ' ');
	return (command_and_options);
}

static void	execute_command(t_pipe *pipe, t_args *args, int i, char *envp[])
{
	char	*cmd_path;
	char	**command_and_options;

	command_and_options = split_command_options(args->commands[i]);
	cmd_path = get_accessible_path(pipe->path, command_and_options[0]);
	execve(cmd_path, command_and_options, envp);
	perror_return("Failed to execute command", 1);
	exit(1);
}

void	execute_pipeline(t_pipe *pipe, \
	t_args *args, int index, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_return("Failed to fork child process", 1);
	else if (pid == 0)
	{
		setup_and_close_child_pipes(pipe, index, args->num_commands);
		execute_command(pipe, args, index, envp);
		perror_return("Failed to execute command", 1);
	}
	else
		pipe->pid[index] = pid;
}
