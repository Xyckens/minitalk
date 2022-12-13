/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:44:35 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/13 17:39:18 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignal(char *str, pid_t p)
{
	int				count;
	unsigned char	c;
	int				bit;

	count = 0;
	while (str[count] != '\0')
	{
		c = (unsigned char) str[count];
		bit = 0;
		while (bit < 8)
		{
			if (c & 0b00000001)
				kill(p, SIGUSR1);
			else
				kill(p, SIGUSR2);
			c >>= 1;
			bit++;
			usleep(30);
		}
		count++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	p;

	if (argc != 3)
		return (0);
	p = ft_atoi(argv[1]);
	sendsignal(argv[2], p);
	return (0);
}
