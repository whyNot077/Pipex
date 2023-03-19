/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:14:24 by minkim3           #+#    #+#             */
/*   Updated: 2022/12/09 19:30:59 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*dummy;

	dummy = (char *)s;
	while (*dummy)
	{
		if (((char)*dummy) == (char)c)
			return (dummy);
		dummy++;
	}
	if ((char)c == '\0')
		return (dummy);
	return (0);
}
