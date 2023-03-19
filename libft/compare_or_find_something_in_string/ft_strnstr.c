/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:56:46 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:34:44 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			index;
	size_t			len_needle;
	size_t			len_haystack;

	index = 0;
	if (*needle == 0)
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (len <= 0 || len_haystack < len_needle)
		return (NULL);
	if (len < len_needle)
		return (NULL);
	while ((index <= (len - len_needle)) && *(haystack + index))
	{
		if (ft_strncmp(haystack + index, needle, len_needle) == 0)
			return ((char *)(haystack + index));
		index++;
	}
	return (NULL);
}
