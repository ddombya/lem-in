/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:39:47 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 17:40:04 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int     ft_countchar(char *str, char c)
{
	int ret;

	ret = 0;
	while (*str)
	{
		if (*str == c)
			ret++;
		str++;
	}
	return (ret);
}