/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:31 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 19:00:10 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	perror_return(const char *message, int status)
{
	perror(message);
	exit(status);
}

void	free_pipe(t_pipe *pipe)
{
	free_two_dementional_array(pipe->path);
	free(pipe);
}
