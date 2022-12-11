/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:02:05 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/23 17:02:07 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	unsigned_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	ft_putlongnbr_fd(unsigned int n, int fd)
{
	unsigned int	digits;
	char			*result;
	int				len;

	if (n == 0)
		return (write (fd, "0", 1));
	digits = unsigned_digits(n);
	len = digits;
	result = malloc((digits + 1) * sizeof(char));
	result[digits--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[digits--] = (n % 10) + 48;
		n = n / 10;
	}
	write(fd, result, len);
	free(result);
	return (len);
}
