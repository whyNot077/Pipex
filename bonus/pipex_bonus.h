/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 16:49:53 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

enum e_definition
{
	ERROR = -1,
	EQUAL = 0,
	SUCCESS = 0,
};

typedef struct s_args
{
	char	*input_file;
	char	*output_file;
	char	**commands;
	int		num_commands;
	bool	here_doc;
	char	*limiter;
}	t_args;

typedef struct s_pipe
{
	int		input_fd;
	int		output_fd;
	int		*pipes;
	pid_t	*pid;
	char	**path;
	char	**commands;
	int		num_commands;
	bool	here_doc;
	char	*limiter;
}	t_pipe;

void	perror_return(const char *message, int status);
void	get_path(t_pipe *pipe, char *envp[]);
t_args	*get_args(int argc, char *argv[]);
char	*get_accessible_path(char **paths, char *command);
void	fork_child_one(t_pipe *pipe, \
	const char *first_command, char *envp[]);
void	fork_child_two(t_pipe *pipe, \
	const char *second_command, char *envp[]);
void	init_pipe(t_args *args, t_pipe *pipe);
void	close_parent(t_pipe *pipe);
void	free_pipe(t_pipe *pipe);

#endif