/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:52 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:33:56 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_numlen(unsigned long long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10 >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_putnum(char *arr, unsigned long long n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	while (n / 10 >= 1)
	{
		arr[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	arr[len - 1 - i] = n + '0';
	return (arr);
}

char	*ft_itoa_extension(unsigned long long n)
{
	char	*arr;
	int		len;

	len = ft_numlen(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr = ft_putnum(arr, n, len);
	arr[len] = '\0';
	return (arr);
}
