/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:39:28 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/21 20:39:08 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		if (ft_strncmp(envp[i], path_key, path_key_len) == 0)
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

char	*get_path(char *command, char *envp[])
{
	char	*path_value;
	char	*path;
	char	*command_path;
	int		path_len;

	path_value = find_path(envp);
	path = ft_strtok(&path_value, ":");
	while (path != NULL)
	{
		path_len = ft_strlen(path);
		command_path = \
			malloc(path_len + ft_strlen("/") + ft_strlen(command) + 1);
		if (!command_path)
			perror_return("Error allocating memory", 1);
		ft_strlcpy(command_path, path, path_len + 1);
		ft_strlcat(command_path, "/", path_len + ft_strlen("/") + 1);
		ft_strlcat(command_path, command, \
			path_len + ft_strlen("/") + ft_strlen(command) + 1);
		ft_printf("Trying: %s\n", command_path);
		if (access(command_path, X_OK) == SUCCESS)
			return (command_path);
		free(command_path);
		path = ft_strtok(&path_value, ":");
	}
	perror_return("Could not find the command path", 1);
	return (NULL);
}
