/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:31:17 by joao-per          #+#    #+#             */
/*   Updated: 2022/10/12 15:31:17 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *variavel, ...);
int		ft_formats(va_list args, const char variavel);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int numero, const char variavel);
int		ft_printpercent(void);

void	ft_putstr(char *str);
void	ft_put_ptr(uintptr_t numero);
int		ft_ptr_len(uintptr_t numero);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int numero);
void	ft_put_hex(unsigned int numero, const char variavel);
int		ft_hex_len(unsigned	int numero);

#endif
