/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:36 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:35:23 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*dummy;

	count = 0;
	dummy = lst;
	while (dummy)
	{
		dummy = dummy -> next;
		count++;
	}
	return (count);
}
