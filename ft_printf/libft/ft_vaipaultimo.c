/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vaipaultimo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:24:26 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/15 10:40:20 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vaipaultimo(char *start, char c)
{
	size_t	i;
	char	*tmp;

	tmp = malloc(ft_strlen(start) + 2);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		tmp[i] = start[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(start);
	return (tmp);
}
