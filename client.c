/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:16:35 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 17:16:48 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**  ------------------------
*	FT_SIGNAL_HANDLER
*	------------------------
*	It's a signal handler that
*	will be called when the server sends a SIGUSR1 signal to the client
* 
*	@param sig The signal number.
*/
static void	ft_signal_handler(int sig)
{
	char	*temp;

	if (sig == SIGUSR1)
	{
		temp = ft_vaipaultimo(g_client, 'a');
		g_client = temp;
	}
}

/**
 *  ------------------------
 *	FT_SEND_MSG
 *  ------------------------
 * It sends a message to the server
 * When it had sent 8 of them, verifies the server answer
 * Waits so that the signs are not ignored
 * 
 * @param pid the process id of the process to send the message to
 * @param s the string to send
 */
static void	ft_send_msg(int pid, char *s)
{
	size_t	i;

	i = 1;
	while (s[i - 1] != '\0')
	{
		if (s[i - 1] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (i % 8 == 0)
		{
			signal(SIGUSR1, ft_signal_handler);
		}
		i++;
		usleep(2000);
	}
}	

/**
 * Converts the string to binary
 * Starts from the end of the string with conversion
 * Puts the binary number at the end of ret
 * Unsigned char so it can handle unicode too
 * 
 * @param s the string to convert
 * @param i the length of the string
 * @param j the index of the bit we're currently on
 * 
 * @return A string of bits.
 */
static char	*ft_to_bit(char *s, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	ret = ft_calloc(i * 8 + 1, sizeof(unsigned char));
	if (ret == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = (unsigned char) s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(s) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}

/**
 * Sends his own PID to the server
 * If the PID less than 8 chars then send 01 till its 8
 * 
 * @param pid the pid of the server
 * @param i the index of the string
 */
static void	ft_send_pid(int pid, int i)
{
	char	*client_pid;
	char	*client_bin;

	client_pid = ft_itoa(getpid());
	client_bin = ft_to_bit(client_pid, 0, 0);
	free(client_pid);
	while (client_bin[i] != '\0')
	{
		if (client_bin[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
	while (i < 56)
	{
		kill(pid, SIGUSR2);
		usleep(80);
		kill(pid, SIGUSR1);
		usleep(80);
		i += 2;
	}
}

/**
 * It sends a message to a process, and then checks if the message
 * was received correctly:
 * Converts his own PID to binary and sends it to the server
 * Converts the message to binary and sends it to the the server
 * Sends 00000000 after eveything has been sent
 * Compares the number of chars to the number of server responses
 * 
 * @param argc number of arguments
 * @param argv 
 * 
 * @return The message sent.
 */
int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("Escreve PID e a mensagem, fds, o que estas a fazer?\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_to_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("Erro de alocacao, fds pcs nao funcionam\n");
		return (0);
	}
	g_client = ft_strdup("");
	ft_send_pid(pid, 0);
	ft_send_msg(pid, bits);
	ft_send_msg(pid, "00000000");
	if (ft_strlen(argv[2]) == ft_strlen(g_client))
		ft_printf("Yap, a mensagem chegou la\n");
	else
		ft_printf("Nope, a mensagem nao chegou la!\n");
	free(g_client);
}
