/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/23 19:48:39 by minkim3          ###   ########.fr       */
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

typedef struct s_pipe
{
	char	*input_file;
	char	*output_file;
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
t_pipe	*get_args(int argc, char *argv[]);
char	*get_accessible_path(char **paths, char *command);
void	open_file(t_pipe *pipe);
void	execute_pipeline(t_pipe *pipe, int index, char *envp[]);
void	create_pipes_and_execute(t_pipe *pipe, char *envp[]);
void	close_pipe(t_pipe *pipe);
void	link_pipes(t_pipe *pipe, int index, int num_commands);
#endif