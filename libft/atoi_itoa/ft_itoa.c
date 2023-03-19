/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:37:54 by minjukim          #+#    #+#             */
/*   Updated: 2023/02/22 17:33:59 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_numlen(int n)
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

static char	*ft_putnum(char *arr, int n, int len)
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

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr = ft_putnum(arr, n, len);
	arr[len] = '\0';
	return (arr);
}
