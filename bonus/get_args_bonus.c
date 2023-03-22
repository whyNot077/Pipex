/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:47 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 16:32:30 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**split_command_options(const char *command)
{
	char	**command_and_options;

	command_and_options = ft_split(command, ' ');
	return (command_and_options);
}

static void	count_commands(int argc, char *argv[], t_args *args)
{
	if (strcmp(argv[1], "here_doc") == EQUAL)
	{
		args->here_doc = true;
		args->num_commands = argc - 5;
	}
	else
	{
		args->here_doc = false;
		args->num_commands = argc - 3;
	}
}

static void	get_command(t_args *args, char *argv[], int start_index)
{
	int	i;

	count_commands(argc, argv, args);
	args->commands = (char **)malloc(sizeof(char *) * (args->num_commands + 1));
	if (!args->commands)
		perror_return("Failed to allocate memory for commands", 1);
	i = 0;
	while (i < args->num_commands)
	{
		args->commands[i] = split_command_options(argv[start_index + i]);
		i++;
	}
	args->commands[args->num_commands] = NULL;
}

static void	parse_arguments(t_args *args, int argc, char *argv[])
{
	if (strcmp(argv[1], "here_doc") == EQUAL)
	{
		args->here_doc = true;
		args->limiter = argv[2];
		args->input_file = NULL;
		args->output_file = argv[argc - 1];
	}
	else
	{
		args->here_doc = false;
		args->limiter = NULL;
		args->input_file = argv[1];
		args->output_file = argv[argc - 1];
	}
}

t_args	*get_args(int argc, char *argv[])
{
	t_args	*args;
	int		start_index;

	if (argc < 5)
		perror_return("Incorrect number of arguments", 1);
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		perror_return("Failed to allocate memory for arguments", 1);
	parse_arguments(args, argc, argv);
	if (args->here_doc)
		start_index = 3;
	else
		start_index = 2;
	get_command(args, argv, start_index);
	return (args);
}
