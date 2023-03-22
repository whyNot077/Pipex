/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 20:57:35 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
	t_args	*args;
	int		i;

	args = get_args(argc, argv);
	pipe = init_pipe(args);
	get_path(pipe, envp);
	create_pipes_and_execute(pipe, args, envp);
	close_parent(pipe);
	i = 0;
	while (i < args->num_commands)
	{
		wait(NULL);
		i++;
	}
	free_pipe(pipe);
	free(args);
	return (0);
}
