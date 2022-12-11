/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:43:24 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/08 19:43:39 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*lista;

	lista = (t_list *) malloc(sizeof(t_list));
	if (lista != NULL)
	{
		lista->content = content;
		lista->next = NULL;
	}
	return (lista);
}
