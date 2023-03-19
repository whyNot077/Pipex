/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:26:44 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:23 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_type_checker(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'c')
		return (1);
	else if (c == '%')
		return (2);
	else if (c == 's')
		return (3);
	else if (c == 'p')
		return (4);
	else if (c == 'u')
		return (5);
	return (0);
}

int	ft_option_error(t_options *string_info)
{
	if (string_info->type == 'c' || string_info->type == 'p')
		if (string_info->precision > 0 || string_info->flag_zero == 1 \
		|| string_info->flag_hash == 1 || string_info->flag_space == 1 \
		|| string_info->flag_plus == 1)
			return (-1);
	if (string_info->type == 'c' || string_info->type == 's' \
	|| string_info->type == 'p')
		if (string_info->flag_zero == 1 || string_info->flag_hash == 1 \
		|| string_info->flag_space == 1 || string_info->flag_plus == 1)
			return (-1);
	if (string_info->type == 'd' || string_info->type == 'i' \
	|| string_info->type == 'u')
		if (string_info->flag_hash == 1)
			return (-1);
	if (string_info->type == 'u' || string_info->type == 'x' \
	|| string_info->type == 'X')
		if (string_info->flag_space == 1 || string_info->flag_plus == 1)
			return (-1);
	if (string_info->flag_zero == 1 && string_info->flag_minus == 1)
		return (-1);
	return (0);
}

int	ft_error_quit(va_list *ap, t_options *string_info)
{
	free(string_info);
	va_end(*ap);
	return (-1);
}
