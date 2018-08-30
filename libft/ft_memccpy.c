/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:21:02 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 11:22:05 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*copy;
	char	*str;
	size_t	i;

	copy = (void *)src;
	str = (void *)dest;
	i = 0;
	while (i < n)
	{
		str[i] = copy[i];
		if (copy[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
