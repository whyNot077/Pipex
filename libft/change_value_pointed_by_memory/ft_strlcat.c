/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:03:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:34:11 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	if (len_src + len_dst < dstsize)
	{
		ft_memcpy(dst + len_dst, src, len_src);
		dst[len_dst + len_src] = '\0';
		return (len_dst + len_src);
	}
	ft_memcpy(dst + len_dst, src, dstsize - len_dst - 1);
	dst[dstsize - 1] = '\0';
	return (len_dst + len_src);
}
