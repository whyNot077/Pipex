/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:17:34 by minjukim          #+#    #+#             */
/*   Updated: 2023/02/22 17:35:36 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	size_t			len_s;

	len_s = ft_strlen(s);
	if (start >= len_s || s == NULL || len_s == 0)
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s + start, len + 1);
	return (arr);
}
