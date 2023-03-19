/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:04:02 by minjukim          #+#    #+#             */
/*   Updated: 2023/02/22 17:33:31 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*res;
	size_t		space;

	space = size * count;
	res = (void *)malloc(space);
	if (!res)
		return (NULL);
	ft_memset(res, 0, count * size);
	return ((void *)res);
}
