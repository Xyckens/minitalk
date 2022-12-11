/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:59:40 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/09 14:59:42 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*sublst;
	t_list	*next;

	if (!lst)
		return ;
	sublst = *lst;
	while (sublst)
	{
		next = sublst->next;
		ft_lstdelone(sublst, del);
		sublst = next;
	}
	*lst = NULL;
}
