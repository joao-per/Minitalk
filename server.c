/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:14:06 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 17:10:35 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern char	*g_client;

static void	ft_del_global(void)
{
	free(g_client);
	g_client = NULL;
}

/**
 * -----------------
 *	FT_CONVERT
 *	-----------------
 *	It converts a binary string to an integer (ascii/unicode)
 *	If it's not to compare, prints the character
 *
 * @param s the string to convert
 * @param b_write 1 if you want to write the character to the standard output,
 * 0 if you want to return the character.
 * 
 * @return The character that is being converted from binary to ASCII.
 */
static int	ft_convert(char *s, int b_write)
{
	int				pow;
	int				c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	if (b_write == 1)
	{
		write(1, &c, 1);
		return (0);
	}
	return (c);
}

/**
 * -----------------
 *	FT_CONFIRM
 * -----------------
 * It converts the binary string into an integer ("bits" variable),
 * and if the integer is an 8bit or 24 bit unicode, it converts
 * In the end, the result is printed and it's sent an ack to the client
 * 
 * @param sig The signal number.
 */
static void	ft_confirm(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_vaipaultimo(bits, '0');
	else
		bits = ft_vaipaultimo(bits, '1');
	if ((bitcount == 8 && ft_convert(bits, 0) < 255) || bitcount == 24)
	{
		if (ft_convert(bits, 0) == 0 && bitcount != 24)
			ft_del_global();
		else
		{
			ft_convert(bits, 1);
			kill(ft_atoi(g_client), SIGUSR1);
		}
		free(bits);
		bits = NULL;
	}
}

/**
 * -----------------
 *	FT_GET_PID
 * -----------------
 * It gets the pid of the client:
 * Keeps all bits inside a string and converts it into a character
 * The character is then sent to the client with the corresponding PID
 * 
 * @param sig The signal number.
 */
static void	ft_get_pid(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_vaipaultimo(bits, '0');
	else
		bits = ft_vaipaultimo(bits, '1');
	if (bitcount == 8)
	{
		g_client = ft_vaipaultimo(g_client, ft_convert(bits, 0));
		free(bits);
		bits = NULL;
	}
}

/**
 * It waits for a client to connect, then waits for the client to send a message:
 * If it doesn't have the client PID, takes 8 bytes from the client PID
 * Otherwise, it decodes the binary to ascii and prints it
 * 
 * @return The PID of the client.
 */
int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	while (1 == 1)
	{
		if (g_client == NULL)
		{
			g_client = ft_strdup("");
			while (ft_strlen(g_client) < 7)
			{
				signal(SIGUSR1, ft_get_pid);
				signal(SIGUSR2, ft_get_pid);
				pause();
			}
			ft_printf("\n");
		}
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (0);
}
