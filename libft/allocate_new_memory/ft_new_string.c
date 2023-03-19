/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:02:33 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 14:28:01 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_new_string(size_t strlen)
{
	char	*new_string;

	new_string = (char *)malloc(sizeof(char) * (strlen));
	if (!new_string)
		return (NULL);
	return (new_string);
}
