/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:44:23 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/12 19:31:26 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("Boring message to tell you pid = %d\n", getpid());
	signaltreatment();
	while (1)
		pause();
	return (0);
}

/*#include "utils.h"

unsigned char	*g_msg = NULL;

void	handler(int signal)
{
	static int				count = 0;
	static unsigned char	c = 0;
	unsigned char			bit;

	bit = (signal == SIGUSR1);
	c |= (bit << count++);
	if (count == 8)
	{
		g_msg = ft_strjoin_mod(g_msg, &c);
		if (!g_msg)
			exit(EXIT_FAILURE);
		if (c == '\0')
		{
			ft_printf("%s\n", g_msg);
			free(g_msg);
			exit(EXIT_SUCCESS);
		}
		count = 0;
		c = 0;
	}
}

void	install_handlers(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	act1.sa_handler = &handler;
	act2.sa_handler = &handler;
	sigemptyset(&act1.sa_mask);
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigemptyset(&act2.sa_mask);
	sigaddset(&act2.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &act1, NULL) == -1)
		print_error("sigaction(): failed handler installing\n");
	if (sigaction(SIGUSR2, &act2, NULL) == -1)
		print_error("sigaction(): failed handler installing\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("PID: %d\n", getpid());
	install_handlers();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}*/