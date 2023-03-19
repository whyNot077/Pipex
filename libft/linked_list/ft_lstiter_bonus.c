/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:11:43 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:35:14 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*dummy;

	dummy = lst;
	if (!dummy)
		return ;
	while (dummy && dummy -> next)
	{
		f(dummy -> content);
		dummy = dummy -> next;
	}
	f(dummy -> content);
}
