/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:37:40 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:34:14 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_nlen_cpy(unsigned char	*src, unsigned char	*dst, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*dummy_src;
	unsigned char	*dummy_dst;
	size_t			src_len;

	src_len = ft_strlen(src);
	dummy_src = (unsigned char *)src;
	dummy_dst = (unsigned char *)dst;
	if (dstsize == 0)
		return (src_len);
	if (src_len < dstsize - 1)
		ft_nlen_cpy(dummy_src, dummy_dst, src_len);
	else
		ft_nlen_cpy(dummy_src, dummy_dst, dstsize - 1);
	return (src_len);
}
