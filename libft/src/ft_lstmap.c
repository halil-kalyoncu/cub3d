/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:16:00 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:20:42 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{	
		ptr = ft_lstnew((f)(lst->content));
		if (!ptr)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&new_lst, ptr);
		lst = lst->next;
	}
	ptr->next = NULL;
	return (new_lst);
}
