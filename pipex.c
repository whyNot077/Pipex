/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:57:57 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 13:08:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
    t_args	*args;

    args = get_args(argc, argv);
    pipe = init_pipe(args->input_file, args->output_file);
    get_path(pipe, envp);
    fork_child_one(pipe, args->first_command, envp);
    fork_child_two(pipe, args->second_command, envp);
    close_parent(pipe);
    waitpid(pipe->pid_one, NULL, 0);
    waitpid(pipe->pid_two, NULL, 0);
    free_pipe(pipe);
    free(args);
	return (0);
}
