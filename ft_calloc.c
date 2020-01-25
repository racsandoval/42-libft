/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:04:00 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/25 18:34:16 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*resp;
	size_t	i;

	resp = malloc(count * size);
	if (!resp)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		resp[i] = 0;
		i++;
	}
	return ((void *)resp);
}
