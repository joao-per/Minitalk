/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:37:13 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/30 23:37:13 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(long long n, int flag)
{
	int len;

	len = 0;
	if (flag == 1 && n >= 0)
	{
		len += ft_putchar('+');
	}
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	flag = 0;
	len += ft_putnbrbase(n, DEC, 0, flag);
	return (len);
}

int	ft_putnbrbase(unsigned long long nbr, char *base, long len, int flag)
{
	size_t	baselen;

	baselen = ft_strlen(base);
	if (!nbr && flag)
		return (ft_putstr("0"));
	if (len == -1 || (flag == 2 && base[10] == 'a'))
	{
		if (!nbr)
			return (ft_putstr("(nil)"));
		len = ft_putstr("0x");
		flag = 0;
	}
	if(base[10] == 'A' && flag == 2)
	{
		len = ft_putstr("0X");
		flag = 0;
	}
	if (nbr >= baselen)
		len = ft_putnbrbase(nbr / baselen, base, len, flag);
	ft_putchar(base[nbr % baselen]);
	return (++len);
}
