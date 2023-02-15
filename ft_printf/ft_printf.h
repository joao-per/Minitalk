/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:37:18 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/30 23:37:18 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXLOW "0123456789abcdef"
# define HEXUP 	"0123456789ABCDEF"
# define DEC 	"0123456789"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*				FT_PRINTF					*/
int		ft_printf(const char *str, ...);

/*				EXTRA FUNCTIONS				*/
int		ft_strlen(char *s);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(long long n, int flag);
int		ft_putnbrbase(unsigned long long nbr, char *base, long len, int flag);

#endif