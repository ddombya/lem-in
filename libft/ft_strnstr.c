/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:23:10 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 13:11:25 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *ha, const char *ne, size_t len)
{
	size_t	n;
	size_t	i;
	char	*s1;
	char	*s2;

	if (*ne == '\0')
		return ((void *)ha);
	n = ft_strlen(ne);
	i = 0;
	s1 = (void *)ha;
	s2 = (void *)ne;
	while (s1[i] && (i + n) <= len)
	{
		if (ft_memcmp(ha + i, ne, n) == 0)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
