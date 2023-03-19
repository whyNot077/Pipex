/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:39:13 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:30 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_decimal_to_string(t_options *string_info, int decimal)
{
	if (decimal == INT_MIN)
	{
		string_info->val_minus = 1;
		string_info->value = ft_strdup("2147483648");
		if (string_info->value == NULL)
			return (ft_malloc_error_void(string_info));
		return ;
	}
	if (decimal < 0)
	{
		string_info->val_minus = 1;
		decimal *= -1;
	}
	string_info->value = ft_itoa(decimal);
	if (string_info->value == NULL)
		return (ft_malloc_error_void(string_info));
}

static int	count_digit_number_for_hexadecimal(unsigned long long decimal)
{
	int	digit_number;

	digit_number = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		digit_number++;
	}
	return (digit_number);
}

void	ft_decimal_to_hexadecimal(t_options *string_info, unsigned int decimal)
{
	int		digit_number;
	char	*result;

	if (decimal == 0)
	{
		string_info->value = ft_strdup("0");
		if (string_info->value == NULL)
			return (ft_malloc_error_void(string_info));
		return ;
	}
	digit_number = \
	count_digit_number_for_hexadecimal((unsigned long long)decimal);
	result = ft_new_string(digit_number + 1);
	if (result == NULL)
		return (ft_malloc_error_void(string_info));
	result[digit_number--] = '\0';
	while (decimal > 0)
	{
		if (string_info->type == 'x')
			result[digit_number--] = "0123456789abcdef"[decimal % 16];
		else if (string_info->type == 'X')
			result[digit_number--] = "0123456789ABCDEF"[decimal % 16];
		decimal /= 16;
	}
	string_info->value = result;
}

char	*ft_pointer_to_lowercase_hexadecimal(unsigned long long decimal)
{
	char	*result;
	size_t	digit_number;

	if (decimal == 0)
	{
		result = ft_strdup("0");
		return (result);
	}
	digit_number = \
	count_digit_number_for_hexadecimal((unsigned long long)decimal) + 2;
	result = ft_new_string(digit_number + 1);
	if (result == NULL)
		return (NULL);
	result[digit_number] = '\0';
	digit_number--;
	while (decimal > 0)
	{
		result[digit_number--] = "0123456789abcdef"[decimal % 16];
		decimal /= 16;
	}
	result[digit_number--] = 'x';
	result[digit_number] = '0';
	return (result);
}
