/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:18:06 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/22 17:35:18 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*dummy_new;
	t_list	*dummy_lst;
	void	*ptr;

	dummy_lst = lst;
	new = NULL;
	dummy_new = new;
	while (dummy_lst)
	{
		ptr = f(dummy_lst -> content);
		dummy_new = ft_lstnew(ptr);
		if (!dummy_new)
		{
			del(ptr);
			ft_lstclear(&new, del);
		}
		ft_lstadd_back(&new, dummy_new);
		dummy_lst = dummy_lst -> next;
	}
	return (new);
}
