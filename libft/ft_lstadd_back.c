/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:40:41 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/10 15:40:44 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*going_to_end;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	going_to_end = *lst;
	while (going_to_end->next != NULL)
		going_to_end = going_to_end->next;
	going_to_end->next = new;
}
