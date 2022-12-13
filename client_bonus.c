/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:13:15 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/13 17:27:08 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignal(char *str, pid_t p)
{
	int				count;
	unsigned char	c;
	int				bit;
	int				lenstr;

	count = 0;
	lenstr = ft_strlen(str);
	while (count <= lenstr)
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

void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received!");
}

void	signaltreatment(void)
{
	struct sigaction	action;

	action.sa_handler = &handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
}

int	main(int argc, char **argv)
{
	pid_t	p;

	if (argc != 3)
		return (0);
	p = ft_atoi(argv[1]);
	signaltreatment();
	sendsignal(argv[2], p);
	while (1)
		pause();
	return (0);
}
