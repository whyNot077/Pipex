/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:52:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/21 21:52:27 by minkim3          ###   ########.fr       */
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

void	close_parent(t_pipe *pipe)
{
	close(pipe->input_fd);
	close(pipe->output_fd);
	close(pipe->pipe_fd[0]);
	close(pipe->pipe_fd[1]);
}
