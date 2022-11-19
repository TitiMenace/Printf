/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:30:11 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/17 18:41:37 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_start;

	new_start = NULL;
	if (lst)
	{	
		ft_lstadd_back(&new_start, ft_lstnew((*f)(lst->content)));
		if (!new_start)
			return (NULL);
		lst = lst->next;
	}
	while (lst != NULL)
	{
		ft_lstadd_back(&new_start, ft_lstnew((*f)(lst->content)));
		if (!new_start)
		{
			ft_lstclear(&new_start, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_start);
}
