/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:05:55 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:14:48 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strsplit_len(char **str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	else
	{
		while (str[len])
			len++;
	}
	return (len);
}
