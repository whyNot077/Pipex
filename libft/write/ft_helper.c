/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:36:16 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/28 09:29:33 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_cpy_with_this(t_options *string_info, char star, int len)
{
	char	*new_string;
	int		copy_len;

	copy_len = len - ft_strlen(string_info->value);
	if (string_info->space != NULL)
		copy_len -= ft_strlen(string_info->space);
	if (string_info->val_minus == 1)
		copy_len--;
	if (copy_len <= 0)
		return (NULL);
	new_string = new_string_with_this(star, copy_len);
	if (new_string == NULL)
		return (ft_malloc_error_null(string_info));
	return (new_string);
}

char	*new_string_with_this(char star, size_t strlen)
{
	char	*new_string;

	new_string = ft_new_string(strlen + 1);
	if (new_string == NULL)
		return (NULL);
	ft_memset(new_string, star, strlen);
	new_string[strlen] = '\0';
	return (new_string);
}

char	*ft_strjoin_three(char	*s1, char *s2, char *s3)
{
	char	*string;
	char	*tmp;

	if (s1 != NULL && s2 != NULL && s3 != NULL)
	{
		tmp = ft_strjoin(s1, s2);
		string = ft_strjoin(tmp, s3);
		free(tmp);
	}
	else if (!s1 && s2 != NULL && s3 != NULL)
		string = ft_strjoin(s2, s3);
	else if (!s2 && s1 != NULL && s3 != NULL)
		string = ft_strjoin(s1, s3);
	else if (!s3 && s1 != NULL && s2 != NULL)
		string = ft_strjoin(s1, s2);
	else if (s1)
		string = ft_strdup(s1);
	else if (s2)
		string = ft_strdup(s2);
	else
		string = ft_strdup(s3);
	return (string);
}

void	ft_putchar(char c, int *strlen)
{
	write(1, &c, 1);
	(*strlen)++;
}
