/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:19:42 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/22 14:20:20 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_hex_digits(unsigned int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	ft_putnbr_hex_fd(unsigned int hex, int fd, int p)
{
	if (hex == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (hex >= 16)
	{
		ft_putnbr_hex_fd(hex / 16, fd, p);
		ft_putnbr_hex_fd(hex % 16, fd, p);
	}
	else if (hex <= 9)
		ft_putchar_fd_(hex + 48, fd);
	else
	{
		if (p == 'X')
			ft_putchar_fd_((hex - 10 + 'A'), fd);
		if (p == 'x')
			ft_putchar_fd_((hex - 10 + 'a'), fd);
	}
	return (count_hex_digits(hex));
}
