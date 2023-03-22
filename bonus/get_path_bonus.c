/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:39:28 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/22 13:33:47 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*find_path(char *envp[])
{
	char	*path_key;
	size_t	path_key_len;
	char	*path;
	int		i;

	path_key = "PATH=";
	path_key_len = ft_strlen(path_key);
	path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], path_key, path_key_len) == EQUAL)
		{
			path = envp[i] + path_key_len;
			break ;
		}
		i++;
	}
	if (path == NULL)
		perror_return("PATH environment variable not found", 1);
	return (path);
}

void	get_path(t_pipe *pipe, char *envp[])
{
	char	*path_value;
	char	**paths;

	path_value = find_path(envp);
	paths = ft_split(path_value, ':');
	pipe->path = paths;
}

char	*get_accessible_path(char **paths, char *command)
{
	char	*command_path;
	int		path_len;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		path_len = ft_strlen(paths[i]);
		command_path = \
			malloc(path_len + ft_strlen("/") + ft_strlen(command) + 1);
		if (!command_path)
			perror_return("Error allocating memory", 1);
		ft_strlcpy(command_path, paths[i], path_len + 1);
		ft_strlcat(command_path, "/", path_len + ft_strlen("/") + 1);
		ft_strlcat(command_path, \
			command, path_len + ft_strlen("/") + ft_strlen(command) + 1);
		if (access(command_path, X_OK) == SUCCESS)
			return (command_path);
		free(command_path);
		i++;
	}
	perror_return("Could not find the command path", 1);
	return (NULL);
}
