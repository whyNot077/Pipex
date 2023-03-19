/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:39:18 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:12 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	flag_hash(t_options *string_info)
{
	if (string_info->flag_hash == 0 || string_info->val_zero == 1 \
	|| string_info->malloc_error == 1)
		return ;
	if (string_info->type == 'x')
		string_info->prefix = "0x";
	else if (string_info->type == 'X')
		string_info->prefix = "0X";
}

static void	flag_space(t_options *string_info)
{
	if (string_info->val_minus == 1)
		string_info->prefix = "-";
	if (string_info->flag_space == 0 || string_info->malloc_error == 1)
		return ;
	else if (string_info->val_minus == 0)
		string_info->prefix = " ";
}

static void	flag_zero(t_options *string_info)
{
	if (string_info->flag_zero == 0 || string_info->space == NULL \
	|| (string_info->precision_have == 1 \
	&& string_info->width - string_info->strlen > 0) \
	|| (string_info->malloc_error == 1) \
	|| (string_info->val_zero == 1 && string_info->width == 1))
		return ;
	ft_memset(string_info->space, '0', ft_strlen(string_info->space));
}

static void	flag_plus(t_options *string_info)
{
	if (string_info->flag_plus == 0 || (string_info->malloc_error == 1))
		return ;
	if (string_info->val_minus == 0)
		string_info->prefix = "+";
}

void	ft_apply_flag(t_options *string_info)
{
	flag_hash(string_info);
	flag_zero(string_info);
	flag_space(string_info);
	flag_plus(string_info);
	ft_apply_flag_minus(string_info);
}
