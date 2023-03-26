/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:52:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/26 14:47:14 by minjukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	open_in_file(t_pipe *pipe)
{
	if (pipe->here_doc == true)
		return ;
	pipe->input_fd = open(pipe->input_file, O_RDONLY);
	if (pipe->input_fd < 0)
		perror_return("Failed to open input file", 1);
}

void	heredoc_open_out_file(t_pipe *pipe)
{
	pipe->output_fd = \
		open(pipe->output_file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (pipe->output_fd < 0)
		perror_return("Failed to open output file", 1);
}

void	open_out_file(t_pipe *pipe)
{
	if (pipe->here_doc == true)
	{
		heredoc_open_out_file(pipe);
		return ;
	}
	pipe->output_fd = \
		open(pipe->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe->output_fd < 0)
		perror_return("Failed to open output file", 1);
}
