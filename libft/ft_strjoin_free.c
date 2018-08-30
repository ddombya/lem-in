/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:38:09 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:48:46 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int free)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 || s2)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
	}
	else
		str = NULL;
	((free == 1 || free == 3) && s1) ? ft_strdel((char **)&s1) : 0;
	((free == 2 || free == 3) && s2) ? ft_strdel((char **)&s2) : 0;
	return (str);
}
