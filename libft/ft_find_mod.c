/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:43:25 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 15:20:29 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_find_mod(char **str, t_flag *flag)
{
	if (**str == 'l' && *(*str + 1) == 'l')
	{
		flag->mod = ll;
		(*str)++;
	}
	else if (**str == 'h' && *(*str + 1) == 'h')
	{
		flag->mod = hh;
		(*str)++;
	}
	else if (**str == 'l')
		flag->mod = l;
	else if (**str == 'h')
		flag->mod = h;
	else if (**str == 'j')
		flag->mod = j;
	else if (**str == 'z')
		flag->mod = z;
	else
		return (*str);
	(*str)++;
	return (*str);
}
