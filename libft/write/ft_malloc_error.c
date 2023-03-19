/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:21:49 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:35 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_malloc_error_int(t_options *string_info)
{
	string_info->malloc_error = 1;
	return (-1);
}

void	*ft_malloc_error_null(t_options *string_info)
{
	string_info->malloc_error = 1;
	return (NULL);
}

void	ft_malloc_error_void(t_options *string_info)
{
	string_info->malloc_error = 1;
	return ;
}
