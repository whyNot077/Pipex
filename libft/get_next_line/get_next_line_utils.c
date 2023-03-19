/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:02:39 by minjukim          #+#    #+#             */
/*   Updated: 2023/02/22 17:34:59 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	find_char(const char *s, int c)
{
	char	*dummy;
	ssize_t	index;

	dummy = (char *)s;
	index = 0;
	while (*(dummy + index))
	{
		if (((char)*(dummy + index)) == (char)c)
			return (index);
		index++;
	}
	if ((char)c == '\0')
		return (index);
	return (-1);
}

char	*append_buffer(char const *s1, char const *s2, size_t len)
{
	char	*arr;
	size_t	len_s1;

	if (s1 == NULL && s2 != NULL)
	{
		arr = malloc(sizeof(char) * (len + 1));
		if (!arr)
			return (NULL);
		ft_strlcpy(arr, s2, len + 1);
		return (arr);
	}
	else if (s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len_s1 + len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1, len_s1 + 1);
	ft_strlcat(arr, s2, len_s1 + len + 1);
	free((void *)s1);
	return (arr);
}
