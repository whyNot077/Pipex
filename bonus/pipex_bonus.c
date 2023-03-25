/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/25 19:51:51 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void leaks()
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	atexit(leaks);
	t_pipe	*pipe;

	pipe = get_args(argc, argv);
	open_file(pipe);
	here_doc(pipe);
	get_path(pipe, envp);
	create_pipes_and_execute(pipe, envp);
	close_pipe(pipe);
	return (0);
}
