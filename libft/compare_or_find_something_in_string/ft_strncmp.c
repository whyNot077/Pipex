/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:51:15 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:34:39 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*dummy1;
	unsigned char	*dummy2;
	size_t			count;

	count = 0;
	dummy1 = (unsigned char *)s1;
	dummy2 = (unsigned char *)s2;
	while (count < n && (*dummy1 || *dummy2))
	{
		if ((*dummy1) != (*dummy2))
			return ((*dummy1) - (*dummy2));
		dummy1++;
		dummy2++;
		count++;
	}
	return (0);
}
