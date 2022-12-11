/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:42:51 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:47:39 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_(int n, int fd)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar_fd_(s[count], fd);
		count++;
	}
	free(s);
	return (count);
}
