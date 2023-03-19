/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:53:46 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_apply_int(t_options *string_info, int value)
{
	char	type;
	char	*string;

	type = string_info->type;
	if (value == 0 && type != 'c')
		string_info->val_zero = 1;
	if (type == 'd' || type == 'i')
		ft_decimal_to_string(string_info, value);
	else if (type == 'x' || type == 'X')
		ft_decimal_to_hexadecimal(string_info, value);
	else if (type == 'c')
	{
		if (value == 0)
			string_info->val_null = 1;
		string = ft_new_string(2);
		if (string == NULL)
			return (ft_malloc_error_void(string_info));
		string[0] = (char)value;
		string[1] = '\0';
		string_info->value = string;
	}
}

void	ft_apply_unsigned_int(t_options *string_info, unsigned int value)
{
	if (value == 0)
		string_info->val_zero = 1;
	string_info->value = ft_itoa_extension(value);
	if (string_info->value == NULL)
		return (ft_malloc_error_void(string_info));
}

void	ft_apply_percent(t_options *string_info, int value)
{
	char	*string;

	string = ft_new_string(2);
	if (string == NULL)
		return (ft_malloc_error_void(string_info));
	string[0] = (char)value;
	string[1] = '\0';
	string_info->value = string;
}

void	ft_apply_string(t_options *string_info, char *value)
{
	if (!value)
	{
		string_info->value = ft_strdup("(null)");
		if (string_info->value == NULL)
			return (ft_malloc_error_void(string_info));
		return ;
	}
	string_info->value = ft_strdup(value);
	if (string_info->value == NULL)
		return (ft_malloc_error_void(string_info));
}

void	ft_apply_pointer(t_options *string_info, unsigned long long value)
{
	if (!value)
	{
		string_info->value = ft_strdup("0x0");
		if (string_info->value == NULL)
			return (ft_malloc_error_void(string_info));
		return ;
	}
	string_info->value = ft_pointer_to_lowercase_hexadecimal(value);
	if (string_info->value == NULL)
		return (ft_malloc_error_void(string_info));
}
