/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:13:18 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/14 12:32:12 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_frase = 0;

void	handler(int signal, siginfo_t *info, void *ucontent)
{
	static int				counter = 0;
	static unsigned char	bin = 0;
	unsigned char			bit;

	(void)ucontent;
	bit = (signal == SIGUSR1);
	bin |= (bit << counter);
	counter++;
	if (counter == 8)
	{
		g_frase = ft_alt_strjoin(g_frase, bin);
		if (bin == '\0')
		{
			ft_printf("%s", g_frase);
			free(g_frase);
			g_frase = 0;
			kill(info->si_pid, SIGUSR1);
		}
		bin = 0;
		counter = 0;
	}
}

void	signaltreatment(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handler;
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
