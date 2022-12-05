/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:57:07 by joao-per          #+#    #+#             */
/*   Updated: 2022/10/12 15:57:07 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_num_len(unsigned	int numero)
{
	int	len;

	len = 0;
	while (numero != 0)
	{
		len++;
		numero = numero / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*numero;
	int		len;

	len = ft_num_len(n);
	numero = (char *)malloc(sizeof(char) * (len + 1));
	if (!numero)
		return (0);
	numero[len] = '\0';
	while (n != 0)
	{
		numero[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (numero);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*numero;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		numero = ft_uitoa(n);
		print_length += ft_printstr(numero);
		free(numero);
	}
	return (print_length);
}
