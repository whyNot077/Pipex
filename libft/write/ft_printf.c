/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:41 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	conversion(const char *format, \
size_t *index, t_options *string_info)
{
	(*index)++;
	ft_memset(string_info, 0, sizeof(t_options));
	while (ft_flag_checker(*(format + (*index))))
		ft_flag_check(*(format + (*index)), string_info, index);
	ft_width_check(format, index, string_info);
	if (*(format + (*index)) == '.')
		ft_precision_check(format, index, string_info);
	if (ft_type_checker(*(format + (*index))) == 0)
		return (-1);
	string_info->type = *(format + (*index));
	if (string_info->type == '%')
		string_info->flag_zero = 0;
	(*index)++;
	return (ft_option_error(string_info));
}

static int	printer(const char *format, va_list *ap, \
t_options *string_info, int *strlen)
{
	size_t		index;
	int			check;

	index = 0;
	while (*(format + index))
	{
		if (ft_percent_or_other(*(format + index)) == -1)
			break ;
		else if (ft_percent_or_other(*(format + index)) == 1)
		{
			if (conversion(format, &index, string_info) == -1)
				return (-1);
			check = ft_apply_option(ap, string_info);
			ft_free_options(string_info);
			if (check == -1)
				return (-1);
			(*strlen) += check;
		}
		else if (ft_percent_or_other(*(format + index)) == 2)
			ft_putchar(*(format + index++), strlen);
	}
	return (0);
}

static int	ft_free_fin(va_list *ap, t_options *string_info, int strlen)
{
	free(string_info);
	va_end(*ap);
	return (strlen);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	*string_info;
	int			strlen;

	strlen = 0;
	string_info = (t_options *)malloc(sizeof(t_options));
	if (string_info == NULL)
		return (-1);
	va_start(ap, format);
	if (printer(format, &ap, string_info, &strlen) == -1)
		return (ft_error_quit(&ap, string_info));
	return (ft_free_fin(&ap, string_info, strlen));
}
