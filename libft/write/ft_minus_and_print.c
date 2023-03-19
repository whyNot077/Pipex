/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:34:34 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:39 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	minus_have(t_options *string_info)
{
	char	*string;
	char	*prefix;
	char	*space;
	int		len;

	prefix = string_info->prefix;
	space = string_info->space;
	len = 0;
	if (string_info->val_null == 1)
	{
		if (space != NULL)
			len = ft_strlen(space);
		string = ft_new_string(len + 2);
		if (string == NULL)
			return (ft_malloc_error_void(string_info));
		string[0] = '\0';
		ft_memset(string + 1, ' ', len);
		string[len + 2] = '\0';
		string_info->print = string;
		return ;
	}
	string = ft_strjoin_three(prefix, string_info->value, space);
	if (string == NULL)
		return (ft_malloc_error_void(string_info));
	string_info->print = string;
}

static void	minus_have_not(t_options *string_info)
{
	char	*string;
	char	*prefix;
	char	*space;

	prefix = string_info->prefix;
	space = string_info->space;
	if ((string_info->flag_zero == 1 && string_info->precision_have == 0) \
	|| (string_info->width_have == 0 && string_info->precision_have == 1))
		string = ft_strjoin_three(prefix, space, string_info->value);
	else
		string = ft_strjoin_three(space, prefix, string_info->value);
	if (string == NULL)
		return (ft_malloc_error_void(string_info));
	string_info->print = string;
}

void	ft_apply_flag_minus(t_options *string_info)
{
	if (string_info->malloc_error == 1)
		return ;
	if (string_info->flag_minus == 1)
		minus_have(string_info);
	else
		minus_have_not(string_info);
}

void	ft_print_t_options(t_options *string_info)
{
	int		strlen;

	strlen = 0;
	if (string_info->print != NULL)
		strlen = ft_strlen(string_info->print);
	if (string_info->val_null == 1)
	{
		strlen = 1;
		if (string_info->space != NULL)
			strlen += ft_strlen(string_info->space);
	}
	write(1, string_info->print, strlen);
	string_info->strlen = strlen;
}

void	ft_free_options(t_options *string_info)
{
	if (string_info->value != NULL)
		free(string_info->value);
	if (string_info->space != NULL)
		free(string_info->space);
	if (string_info->print != NULL)
		free(string_info->print);
}
