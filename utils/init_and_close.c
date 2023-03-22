/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:52:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 13:05:31 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe	*init_pipe(const char *input_file, const char *output_file)
{
	t_pipe	*init_pipe;

	init_pipe = calloc(1, sizeof(t_pipe));
	init_pipe->input_fd = open(input_file, O_RDONLY);
	if (init_pipe->input_fd == ERROR)
		perror_return("Error opening input file", 1);
	init_pipe->output_fd = \
			open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (init_pipe->output_fd == ERROR)
		perror_return("Error opening output file", 1);
	if (pipe(init_pipe->pipe_fd) == ERROR)
		perror_return("Error creating pipe", 1);
	return (init_pipe);
}

t_args *get_args(int argc, char *argv[])
{
	t_args	*args;

	if (argc != 5)
		perror_return("Incorrect number of arguments", 1);
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		perror_return("Failed to allocate memory for arguments", 1);
	args->input_file = argv[1];
	args->first_command = argv[2];
	args->second_command = argv[3];
	args->output_file = argv[4];
	return (args);
}

void	close_parent(t_pipe *pipe)
{
	close(pipe->input_fd);
	close(pipe->output_fd);
	close(pipe->pipe_fd[0]);
	close(pipe->pipe_fd[1]);
}

void	free_pipe(t_pipe *pipe)
{
	free_two_dementional_array(pipe->path);
	free(pipe);	
}
