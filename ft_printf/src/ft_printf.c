/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:26:05 by joao-per          #+#    #+#             */
/*   Updated: 2022/10/12 16:26:05 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_variaveis(va_list args, const char variavel)
{
	int	print_length;

	print_length = 0;
	if (variavel == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (variavel == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (variavel == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (variavel == 'd' || variavel == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (variavel == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (variavel == 'x' || variavel == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), variavel);
	else if (variavel == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_variaveis(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
