/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:43:07 by minjukim          #+#    #+#             */
/*   Updated: 2023/02/22 17:35:35 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_inset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	len_s1;
	size_t	start;
	size_t	end;

	start = 0;
	if (*s1 == '\0')
		return (ft_strdup(""));
	len_s1 = ft_strlen(s1);
	while (ft_inset(s1[start], set))
		start++;
	end = len_s1 - 1;
	while (ft_inset(s1[end], set))
	{
		if (end == 0)
			return (ft_strdup(""));
		end--;
	}
	if (end < start)
		return (ft_strdup(""));
	arr = ft_substr(s1, start, end - start + 1);
	return (arr);
}
