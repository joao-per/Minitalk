/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:14:00 by joao-per          #+#    #+#             */
/*   Updated: 2023/02/13 12:14:00 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	signal;
	int					pid;

	if (ac != 1)
	{
		ft_printf("\033[91mError\n");
		ft_printf("\033[33mFormat: %s\n", av[0]);
		return (0);
	}
	pid = getpid();
	ft_printf("\033[94mProcessor ID \033[96m==>\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	signal.sa_sigaction = ft_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}
