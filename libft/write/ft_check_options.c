/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:58:21 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:27 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_percent_or_other(char c)
{
	if (c == '%')
		return (1);
	else if (c == '\0')
		return (-1);
	return (2);
}

int	ft_flag_checker(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

void	ft_flag_check(char c, t_options *string_info, size_t *index)
{
	if (c == '-')
		string_info->flag_minus = 1;
	else if (c == '+')
		string_info->flag_plus = 1;
	else if (c == ' ')
		string_info->flag_space = 1;
	else if (c == '0')
		string_info->flag_zero = 1;
	else if (c == '#')
		string_info->flag_hash = 1;
	(*index)++;
}

void	ft_width_check(const char *format, size_t *index, \
t_options *string_info)
{
	size_t	num;
	char	c;

	num = 0;
	c = *(format + (*index));
	if ((c < '0') || (c > '9'))
		return ;
	while ((c >= '0') && (c <= '9'))
	{
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + *(index));
	}
	if (((int)num > INT_MAX) || ((long)num < INT_MIN))
		num = -1;
	string_info->width_have = 1;
	string_info->width = (int)num;
}

void	ft_precision_check(const char *format, size_t *index, \
t_options *string_info)
{
	size_t	num;
	char	c;

	num = 0;
	(*index)++;
	string_info->precision_have = 1;
	c = *(format + (*index));
	if ((c < '0') || (c > '9'))
		return ;
	while ((c >= '0') && (c <= '9'))
	{
		num *= 10;
		num += (c - '0');
		(*index)++;
		c = *(format + (*index));
	}
	if (((int)num > INT_MAX) || ((long)num < INT_MIN))
			num = -1;
	string_info->precision = (int)num;
}
