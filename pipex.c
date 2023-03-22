/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 12:59:02 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/pipex.h"

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
	free_pipe(pipe);
	return (0);
}
