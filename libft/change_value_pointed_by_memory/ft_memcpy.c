/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:46 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:34:05 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*dummy_dst;
	unsigned char	*dummy_src;

	count = 0;
	dummy_dst = (unsigned char *)dst;
	dummy_src = (unsigned char *)src;
	if (dummy_dst == NULL && dummy_src == NULL)
		return (NULL);
	while (count < n)
	{
		*dummy_dst++ = *dummy_src++;
		count++;
	}
	return (dst);
}
