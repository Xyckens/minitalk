/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:06 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/09 15:00:09 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*novalst_elem;
	t_list	*novalst;

	novalst_elem = ft_lstnew(f(lst->content));
	if (!lst || !f || novalst_elem == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	novalst = novalst_elem;
	lst = lst->next;
	while (lst)
	{
		novalst_elem = ft_lstnew(f(lst->content));
		if (novalst_elem == NULL)
		{
			ft_lstclear(&novalst_elem, del);
			ft_lstclear(&lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&novalst, novalst_elem);
	}
	return (novalst);
}
