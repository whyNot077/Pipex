/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:06:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/26 14:47:25 by minjukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static int	get_line_heardoc(t_pipe *t_pipe, int pipe_fd)
{
	char	*line;

	line = NULL;
	write(1, "heredoc> ", 9);
	line = get_next_line(STDIN_FILENO);
	if (line == NULL)
		perror_return("Failed to read from stdin for here_doc", 1);
	if (ft_strcmp(line, t_pipe->limiter) == EQUAL)
	{
		free(line);
		return (FIN);
	}
	if (write(pipe_fd, line, ft_strlen(line)) == -1)
	{
		free(line);
		perror_return("Failed to write to pipe for here_doc", 1);
	}
	free(line);
	return (0);
}

void	here_doc(t_pipe *t_pipe)
{
	int		pipe_fds[2];

	if (t_pipe->here_doc == false)
		return ;
	if (pipe(pipe_fds) == -1)
		perror_return("Failed to create pipe for here_doc", 1);
	while (1)
	{
		if (get_line_heardoc(t_pipe, pipe_fds[1]) == FIN)
			break ;
	}
	close(pipe_fds[1]);
	t_pipe->input_fd = pipe_fds[0];
}
