/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:47 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/24 15:50:01 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	count_commands(int argc, char *argv[], t_pipe *pipe)
{
	if (strcmp(argv[1], "here_doc") == EQUAL)
	{
		pipe->here_doc = true;
		pipe->num_commands = argc - 4;
	}
	else
	{
		pipe->here_doc = false;
		pipe->num_commands = argc - 3;
	}
}

static void	get_command(t_pipe *pipe, char *argv[], int start_index, int argc)
{
	int	i;

	count_commands(argc, argv, pipe);
	pipe->commands = (char **)malloc(sizeof(char *) * (pipe->num_commands + 1));
	if (!pipe->commands)
		perror_return("Failed to allocate memory for commands", 1);
	i = 0;
	while (i < pipe->num_commands)
	{
		pipe->commands[i] = argv[start_index + i];
		i++;
	}
	pipe->commands[pipe->num_commands] = NULL;
}

static void	parse_arguments(t_pipe *pipe, int argc, char *argv[])
{
	if (ft_strcmp(argv[1], "here_doc") == EQUAL)
	{
		pipe->here_doc = true;
		pipe->limiter = ft_strjoin(argv[2], "\n");
		pipe->input_file = NULL;
		pipe->output_file = argv[argc - 1];
	}
	else
	{
		pipe->here_doc = false;
		pipe->limiter = NULL;
		pipe->input_file = argv[1];
		pipe->output_file = argv[argc - 1];
	}
}

static void	init_pipe(t_pipe *pipe)
{
	pipe->input_fd = -1;
	pipe->output_fd = -1;
	pipe->pipes = (int **)malloc(sizeof(int *) * (pipe->num_commands - 1));
	if (!pipe->pipes)
		perror_return("Failed to allocate memory for pipes", 1);
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * pipe->num_commands);
	if (!pipe->pid)
		perror_return("Failed to allocate memory for PIDs", 1);
}

t_pipe	*get_args(int argc, char *argv[])
{
	t_pipe	*pipe;
	int		start_index;

	if (argc < 5)
		perror_return("Incorrect number of arguments", 1);
	pipe = ft_calloc(1, sizeof(t_pipe));
	if (!pipe)
		perror_return("Failed to allocate memory for arguments", 1);
	parse_arguments(pipe, argc, argv);
	if (pipe->here_doc)
		start_index = 3;
	else
		start_index = 2;
	get_command(pipe, argv, start_index, argc);
	init_pipe(pipe);
	return (pipe);
}
