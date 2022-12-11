/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:37:24 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/21 13:37:26 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_encontreipercent(char p, va_list args, int fd)
{
	if (p == 'c')
	{
		ft_putchar_fd_(va_arg(args, int), fd);
		return (1);
	}
	else if (p == 's')
		return (ft_putstr_fd_(va_arg(args, char *), fd));
	else if (p == 'p')
		return (ft_print_pointer_fd(va_arg(args, unsigned long long), fd));
	else if (p == 'd' || p == 'i')
		return (ft_putnbr_fd_(va_arg(args, int), fd));
	else if (p == 'u')
		return (ft_putlongnbr_fd(va_arg(args, unsigned int), fd));
	else if (p == 'x')
		return (ft_putnbr_hex_fd(va_arg(args, unsigned int), fd, p));
	else if (p == 'X')
		return (ft_putnbr_hex_fd(va_arg(args, unsigned int), fd, p));
	else if (p == '%')
	{
		ft_putchar_fd_('%', fd);
		return (1);
	}
	else
		return (ft_putstr_fd_("erro", fd));
}

int	ft_printf(const char *fds, ...)
{
	va_list	args;
	int		count;
	int		count2;

	va_start(args, fds);
	count = 0;
	count2 = 0;
	while (fds[count] != '\0')
	{
		if (fds[count] != '%')
		{
			count2++;
			ft_putchar_fd_(fds[count], 1);
		}
		if (fds[count] == '%')
		{
			count2 += ft_encontreipercent(fds[count + 1], args, 1);
			count++;
		}
		count++;
	}
	va_end(args);
	return (count2);
}
