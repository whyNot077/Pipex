/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:36:08 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 17:17:42 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void create_pipes(int *pipes, int num_commands)
{
	int i;

	i = 0;
	while (i < num_commands - 1)
	{
		if (pipe2(pipes + i * 2, O_CLOEXEC) == -1)
			perror_return("Failed to create pipe", 1);
		i++;
	}
}

static void setup_and_close_child_pipes(t_pipe *pipe, int i, int num_commands, int *pipes)
{
    int j;

	j = 0;
    if (i != 0)
        dup2(pipes[(i - 1) * 2], 0);
    else
        dup2(pipe->input_fd, 0);
    if (i != num_commands - 1)
        dup2(pipes[i * 2 + 1], 1);
    else
        dup2(pipe->output_fd, 1);
    while (j < (num_commands - 1) * 2)
    {
        close(pipes[j]);
        j++;
    }
}

static void execute_command(t_pipe *pipe, t_args *args, int i, char *envp[])
{
	char *cmd_path;
	char **cmd_and_options;

	cmd_path = get_accessible_path(pipe->path, args->commands[i]);
	if (!cmd_path)
	{
		fprintf(stderr, "Command not found: %s\n", args->commands[i]);
		exit(1);
	}
	cmd_and_options = split_command_options(args->commands[i]);
	execve(cmd_path, cmd_and_options, envp);
	perror("Failed to execute command");
	exit(1);
}

void fork_childs(t_pipe *pipe, t_args *args, char *envp[])
{
	int		i;
	int		num_commands;
	int		*pipes;
	pid_t	pid;

	i = 0;
	num_commands = args->num_commands;
	pipes = (int *)malloc(sizeof(int) * (num_commands - 1) * 2);
	if (!pipes)
		perror_return("Failed to allocate memory for pipes", 1);
	create_pipes(pipes, num_commands);
	pipe->pipes = pipes;
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * num_commands);
	if (!pipe->pid)
		perror_return("Failed to allocate memory for PIDs", 1);
	while (i < num_commands)
	{
		pid = fork();
		if (pid < 0)
			perror_return("Failed to fork child process", 1);
		else if (pid == 0)
		{
			setup_and_close_child_pipes(pipe, i, num_commands, pipes);
			execute_command(pipe, args, i, envp);
		}
		else
			pipe->pid[i] = pid;
		i++;
	}
	close_parent(pipe);
}
