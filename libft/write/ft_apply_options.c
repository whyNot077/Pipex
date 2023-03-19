/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:18:56 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:16 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	precision_zero(t_options *string_info, char *string, \
int precision)
{
	char	*cpy_string;

	cpy_string = new_string_with_this('0', precision);
	if (cpy_string == NULL)
		return (ft_malloc_error_void(string_info));
	string_info->value = cpy_string;
	free(string);
}

static void	precision_number(t_options *string_info, char *string, \
int precision)
{
	char	*cpy_string;
	char	*new_string;

	if (string_info->val_zero == 1)
		return (precision_zero(string_info, string, precision));
	if (string_info->val_minus == 1)
		cpy_string = ft_get_cpy_with_this(string_info, '0', precision + 1);
	else
		cpy_string = ft_get_cpy_with_this(string_info, '0', precision);
	if (string_info->malloc_error == 1 || cpy_string == NULL)
		return ;
	new_string = ft_strjoin(cpy_string, string);
	if (new_string == NULL)
		return (ft_malloc_error_void(string_info));
	string_info->value = new_string;
	free(string);
	free(cpy_string);
}

static void	ft_apply_precision(t_options *string_info)
{
	char	*string;
	char	*new_string;
	int		precision;

	if (string_info->precision_have == 0 || string_info->malloc_error == 1)
		return ;
	precision = string_info->precision;
	string = string_info->value;
	new_string = NULL;
	if (string == NULL || string_info->type == 's')
	{
		if (string == NULL)
			new_string = new_string_with_this('0', precision);
		else if (string_info->type == 's')
			new_string = ft_substr(string, 0, precision);
		if (new_string == NULL)
			return (ft_malloc_error_void(string_info));
		string_info->value = new_string;
		free(string);
		return ;
	}
	precision_number(string_info, string, precision);
}

static void	ft_apply_width(t_options *string_info)
{
	char	*cpy_string;
	char	*string;

	string = string_info->value;
	if ((string_info->width_have == 0) || (string_info->malloc_error == 1) \
	|| (ft_strlen(string) >= (size_t)(string_info->width)))
		return ;
	if ((string_info->val_null == 1) || ((string_info->val_minus == 0) \
	&& (string_info->flag_space == 1 || string_info->flag_plus == 1)))
		cpy_string = \
		ft_get_cpy_with_this(string_info, ' ', string_info->width - 1);
	else if (string_info->flag_hash == 1 && string_info->val_zero == 0)
		cpy_string = \
		ft_get_cpy_with_this(string_info, ' ', string_info->width - 2);
	else
		cpy_string = ft_get_cpy_with_this(string_info, ' ', string_info->width);
	if (string_info->malloc_error == 1 || cpy_string == NULL)
		return ;
	string_info->space = cpy_string;
}

int	ft_apply_option(va_list *ap, t_options *string_info)
{
	int	type;

	type = ft_type_checker(string_info->type);
	if (type == 1)
		ft_apply_int(string_info, va_arg(*ap, int));
	else if (type == 2)
		ft_apply_percent(string_info, '%');
	else if (type == 3)
		ft_apply_string(string_info, va_arg(*ap, char *));
	else if (type == 4)
		ft_apply_pointer(string_info, va_arg(*ap, unsigned long long));
	else if (type == 5)
		ft_apply_unsigned_int(string_info, va_arg(*ap, unsigned int));
	if (string_info->value != NULL)
		string_info->strlen = ft_strlen(string_info->value);
	ft_apply_precision(string_info);
	ft_apply_width(string_info);
	ft_apply_flag(string_info);
	if (string_info->malloc_error == 1)
		return (-1);
	ft_print_t_options(string_info);
	return (string_info->strlen);
}
