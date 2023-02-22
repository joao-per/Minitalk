/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:09:07 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/14 18:09:07 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h> 

/*				CLIENT				*/
void	ft_send_bits(int pid, char i);

/*				SERVER				*/
void	ft_handler(int signal, siginfo_t *info, void *s);

int		ft_atoi(const char *str);

#endif
