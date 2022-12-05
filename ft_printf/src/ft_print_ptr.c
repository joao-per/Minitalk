/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:45:21 by joao-per          #+#    #+#             */
/*   Updated: 2022/10/12 15:45:21 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_ptr_len(uintptr_t numero)
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

void	ft_put_ptr(uintptr_t numero)
{
	if (numero >= 16)
	{
		ft_put_ptr(numero / 16);
		ft_put_ptr(numero % 16);
	}
	else
	{
		if (numero <= 9)
			ft_putchar_fd((numero + '0'), 1);
		else
			ft_putchar_fd((numero - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
		print_length += write(1, "(nil)", 5);
	else
	{
		print_length += write(1, "0x", 2);
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
