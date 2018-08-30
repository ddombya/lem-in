/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:42:27 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 12:47:59 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_first_blankspace(char const *str)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
	{
		count++;
		i++;
	}
	return (count);
}

static size_t	ft_last_blankspace(char const *str)
{
	size_t i;
	size_t count;
	size_t len;

	len = ft_strlen(str);
	i = len - 1;
	count = 0;
	if (len == 0)
		return (0);
	while (i > 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
	{
		count++;
		i--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	begin;
	size_t	end;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	begin = ft_first_blankspace(s);
	end = ft_last_blankspace(s);
	i = 0;
	len = ft_strlen(s);
	if (len - begin <= 0)
		return (ft_strdup(""));
	str = ft_strnew(len - begin - end);
	if (!str)
		return (NULL);
	while (s[begin] && begin < len - end)
	{
		str[i] = s[begin];
		i++;
		begin++;
	}
	return (str);
}
