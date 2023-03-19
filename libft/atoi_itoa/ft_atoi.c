/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:43:37 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/03 19:00:40 by minjukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((9 <= str[*i] && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;
	char	c;

	res = 0;
	i = 0;
	sign = ft_sign(str, &i);
	while (str[i])
	{
		c = (char)str[i++];
		if ('0' <= c && c <= '9')
		{
			res *= 10;
			res += (c - '0');
		}
		else
			return (res * sign);
	}
	return (res * sign);
}
