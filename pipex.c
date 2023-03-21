/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/21 21:37:12 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipe	*init_pipe(const char *input_file, const char *output_file)
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

static void	close_parent(t_pipe *pipe)
{
	close(pipe->input_fd);
	close(pipe->output_fd);
	close(pipe->pipe_fd[0]);
	close(pipe->pipe_fd[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
	char	*input_file;
	char	*first_command;
	char	*second_command;
	char	*output_file;

	if (argc != 5)
		perror_return("Incorrect number of arguments", 1);
	input_file = argv[1];
	first_command = argv[2];
	second_command = argv[3];
	output_file = argv[4];
	pipe = init_pipe(input_file, output_file);
	get_path(pipe, envp);
	fork_child_one(pipe, first_command, envp);
	fork_child_two(pipe, second_command, envp);
	close_parent(pipe);
	waitpid(pipe->pid_one, NULL, 0);
	waitpid(pipe->pid_two, NULL, 0);
	free_two_dementional_array(pipe->path);
	free(pipe);
	return (0);
}
