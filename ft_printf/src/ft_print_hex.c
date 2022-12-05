/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:39:48 by joao-per          #+#    #+#             */
/*   Updated: 2022/10/12 15:39:48 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(unsigned	int numero)
{
	int	len;

	len = 0;
	while (numero != 0)
	{
		len++;
		numero = numero / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int numero, const char variavel)
{
	if (numero >= 16)
	{
		ft_put_hex(numero / 16, variavel);
		ft_put_hex(numero % 16, variavel);
	}
	else
	{
		if (numero <= 9)
			ft_putchar_fd((numero + '0'), 1);
		else
		{
			if (variavel == 'x')
				ft_putchar_fd((numero - 10 + 'a'), 1);
			if (variavel == 'X')
				ft_putchar_fd((numero - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int numero, const char variavel)
{
	if (numero == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(numero, variavel);
	return (ft_hex_len(numero));
}
