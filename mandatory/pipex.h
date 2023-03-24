/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/24 14:17:34 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
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

typedef struct s_args
{
	char	*input_file;
	char	*first_command;
	char	*second_command;
	char	*output_file;
}	t_args;

typedef struct s_pipe
{
	int		input_fd;
	int		output_fd;
	int		pipe_fd[2];
	pid_t	pid_one;
	pid_t	pid_two;
	char	**path;
}	t_pipe;

void	perror_return(const char *message, int status);
void	get_path(t_pipe *pipe, char *envp[]);
t_args	*get_args(int argc, char *argv[]);
char	*get_accessible_path(char **paths, char *command);
void	fork_child_one(t_pipe *pipe, \
	const char *first_command, char *envp[]);
void	fork_child_two(t_pipe *pipe, \
	const char *second_command, char *envp[]);
t_pipe	*init_pipe(const char *input_file, const char *output_file);
void	close_parent(t_pipe *pipe);
void	free_pipe(t_pipe *pipe);

#endif