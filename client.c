/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:14:06 by joao-per          #+#    #+#             */
/*   Updated: 2023/02/13 12:14:06 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int signal)
{
	static int i = 0;
	
	if (signal == SIGUSR2)
	{
		i++;
		if(i == message_len)
		{
			ft_printf("\033[0;32mSUCCESS!\033[94m\n");
			ft_printf("Server Received %d \033[94mcharacters!\n", i);
		}
	}
}

void	send_message(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	message_len = strlen(av[2]);
	i = 0;
	if (ac != 3)
	{
		ft_printf("\033[91mError\n");
		ft_printf("\033[33mFormat: %s (PID) (MESSAGE)\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i] != '\0')
	{
		signal(SIGUSR2, ft_confirm);
		send_message(pid, av[2][i]);
		i++;
	}
	send_message(pid, '\n');
	return (0);
}
