/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:44:35 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/12 20:32:17 by fvieira          ###   ########.fr       */
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
/*#include "utils.h"

void	send_letter(pid_t spid, unsigned char c)
{
	int	i;

	i = 0;
	ft_printf("Sending 0x%X (%c)\n", c, c);
	while (i++ < 8)
	{
		if (c & 0b00000001)
		{
			if (kill(spid, SIGUSR1) == -1)
				print_error("kill(): couldn't transmit bit to server\n");
		}
		else
		{
			if (kill(spid, SIGUSR2) == -1)
				print_error("kill(): couldn't transmit bit to server\n");
		}
		c >>= 1;
		usleep(100);
	}
}

void	send_message(pid_t spid, char *msg)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(msg);
	while (i <= len)
		send_letter(spid, msg[i++]);
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc != 3)
		print_usage(argv[0]);
	spid = ft_atoi(argv[1]);
	send_message(spid, argv[2]);
	return (EXIT_SUCCESS);
}*/