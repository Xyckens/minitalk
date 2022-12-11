/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:38:11 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:41:03 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (s[count] != '\0')
	{
		ft_putchar_fd_(s[count], fd);
		count++;
	}
	return (count);
}
