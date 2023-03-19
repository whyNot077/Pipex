/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:49:17 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:35:27 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_make_col(char const *s, char c, int *count_col)
{
	int		i;
	char	**arr;

	i = -1;
	while (s[++i])
	{
		if ((i > 0) && (s[i] != c) && s[i - 1] == c)
			(*count_col) += 1;
	}
	if ((s[0] != c) && (s[0] != '\0'))
		(*count_col) += 1;
	arr = (char **)malloc(sizeof(char *) * ((*count_col) + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

static char	*ft_make_row(char const *s, char c, int *start, int *end)
{
	int		j;
	char	*arr;

	j = 0;
	while (s[(*start)] == c)
		(*start)++;
	(*end) = (*start);
	while ((s[(*end)] != c) && s[(*end)])
		(*end)++;
	arr = (char *)malloc(sizeof(char) * ((*end) - (*start) + 1));
	if (!arr)
		return (NULL);
	while ((*start) < (*end))
		arr[j++] = s[(*start)++];
	arr[j] = '\0';
	return (arr);
}

static char	**ft_free_all(char **arr, int point)
{
	int	i;

	i = 0;
	while (i < point)
		free (arr[i++]);
	free (arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count_col;
	int		start;
	int		end;
	int		i;

	i = 0;
	count_col = 0;
	start = 0;
	end = 0;
	arr = ft_make_col(s, c, &count_col);
	if (!arr)
		return (NULL);
	while (i < count_col)
	{
		arr[i] = ft_make_row(s, c, &start, &end);
		if (!arr[i])
			return (ft_free_all(arr, i));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
