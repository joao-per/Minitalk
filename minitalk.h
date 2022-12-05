/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:15:55 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/15 12:15:52 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/include/ft_printf.h"
# include "ft_printf/include/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

char	*g_client;
char	*ft_vaipaultimo(char *start, char c);

#endif