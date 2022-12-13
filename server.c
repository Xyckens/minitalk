/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:44:23 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/13 17:39:31 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int				counter = 0;
	static unsigned char	bin = 0;
	unsigned char			bit;

	bit = (signal == SIGUSR1);
	bin |= (bit << counter);
	counter++;
	if (counter == 8)
	{
		ft_putchar_fd(bin, 1);
		bin = 0;
		counter = 0;
	}
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

int	main(void)
{
	ft_printf("Boring message to tell you pid = %d\n", getpid());
	signaltreatment();
	while (1)
		pause();
	return (0);
}
