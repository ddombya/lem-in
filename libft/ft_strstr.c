/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:29:44 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 12:31:08 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *begin;
	char *to_find;

	if (*needle == '\0')
		return ((void *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			begin = (void *)haystack + 1;
			to_find = (void *)needle + 1;
			while (*begin && *to_find && (*begin == *to_find))
			{
				begin++;
				to_find++;
			}
			if (*to_find == '\0')
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
