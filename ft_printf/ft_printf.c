/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:37:19 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/30 23:37:19 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_type(char format, va_list args, int flag)
{
	int	rt_size;

	rt_size = 0;
	if (format == 'c')
		rt_size = ft_putchar(va_arg(args, int));
	else if (format == 's')
		rt_size = ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		rt_size = ft_putnbr(va_arg(args, int), flag);
	else if (format == 'u')
		rt_size = ft_putnbrbase(va_arg(args, unsigned int), DEC, 0, flag);
	else if (format == 'x')
		rt_size = ft_putnbrbase(va_arg(args, unsigned int), HEXLOW, 0, flag);
	else if (format == 'X')
		rt_size = ft_putnbrbase(va_arg(args, unsigned int), HEXUP, 0, flag);
	else if (format == 'p')
		rt_size = ft_putnbrbase(va_arg(args, unsigned long long), HEXLOW, -1, flag);
	else if (format == '%')
		rt_size = ft_putchar('%');
	return (rt_size);
}

int ft_flags(char type)
{
	int flag;

	flag = 0;
	if (type == '+')
		flag = 1;
	if (type == '#')
		flag = 2;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		rt_size;
	int		flag;
	int		i;

	va_start(args, str);
	i = 0;
	rt_size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = ft_flags(str[i + 1]);
			if (flag)
				i++;
			rt_size += format_type(str[i++ + 1], args, flag);
		}
		else
			rt_size += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (rt_size);
}
