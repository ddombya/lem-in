/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:00:56 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 15:19:46 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char		*ft_find_conv(char **str, t_flag *flag)
{
	if (**str == 'c')
		flag->conv = c;
	else if (**str == 'C')
		flag->conv = C;
	else if (**str == '%')
		flag->conv = pct;
	else if (**str == 'u' || **str == 'U')
	{
		flag->conv = u;
		if (**str == 'U')
			flag->mod = l;
	}
	else if (**str == 'x')
		flag->conv = x;
	else if (**str == 'X')
		flag->conv = X;
	else
	{
		flag->conv = ch;
		flag->c = **str;
	}
	(*str)++;
	return (*str);
}

char			*ft_find_conversion(char **str, t_flag *flag)
{
	if (**str == 'd' || **str == 'D' || **str == 'i')
	{
		flag->conv = d;
		if (**str == 'D')
			flag->mod = l;
	}
	else if (**str == 's')
		flag->conv = s;
	else if (**str == 'S')
		flag->conv = S;
	else if (**str == 'p')
		flag->conv = p;
	else if (**str == 'b')
		flag->conv = b;
	else if (**str == 'o' || **str == 'O')
	{
		flag->conv = o;
		if (**str == 'O')
			flag->mod = l;
	}
	else
		return (ft_find_conv(str, flag));
	(*str)++;
	return (*str);
}
