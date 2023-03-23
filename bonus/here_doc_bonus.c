/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:06:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/23 22:45:11 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_pipe *t_pipe)
{
    char *line;
    int pipe_fds[2];

    if (pipe(pipe_fds) == -1)
        perror_return("Failed to create pipe for here_doc", 1);
	line = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			perror_return("Failed to read from stdin for here_doc", 1);
		if (ft_strcmp(line, t_pipe->limiter) == EQUAL)
		{
			free(line);
			break ;
		}
		if (write(pipe_fds[1], line, ft_strlen(line)) == -1)
		{
			free(line);
			perror_return("Failed to write to pipe for here_doc", 1);
		}
		free(line);
	}
    close(pipe_fds[1]);
    t_pipe->input_fd = pipe_fds[0];
}
