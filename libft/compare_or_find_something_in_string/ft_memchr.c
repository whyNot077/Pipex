/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:09:03 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:34:32 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cmpchr(unsigned char a, unsigned char b)
{
	if (a == b)
		return (1);
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dummy;
	size_t			index;

	index = 0;
	dummy = (unsigned char *)s;
	while (index < n)
	{
		if (ft_cmpchr(*(dummy + index), (unsigned char)c))
			return ((void *)(dummy + index));
		index++;
	}
	return (0);
}
