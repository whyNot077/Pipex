/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/20 15:45:12 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>

enum e_definition
{
	ERROR = -1,
	EQUAL = 0,
	SUCCESS = 0,
};

typedef struct s_pipe
{
	int		input_fd;
	int		output_fd;
	int		pipe_fd[2];
	pid_t	pid_one;
	pid_t	pid_two;
	char	*path;
}	t_pipe;

void	perror_return(const char *message, int status);

#endif