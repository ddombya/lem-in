/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:06:36 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/20 16:14:28 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_print_opt(int len, int opt, char c)
{
	int i;

	i = 0;
	while (opt > len)
	{
		ft_putchar(c);
		opt--;
		i++;
	}
	return (i);
}

intmax_t	ft_print_signed(t_flag *flag, intmax_t nb)
{
	if (flag->mod == h)
		return ((short)nb);
	else if (flag->mod == hh)
		return ((signed char)nb);
	else if (flag->mod == l)
		return ((long)nb);
	else if (flag->mod == ll)
		return ((long long)nb);
	else if (flag->mod == j)
		return (nb);
	else if (flag->mod == z)
		return ((size_t)nb);
	else
		return ((int)nb);
}

uintmax_t	ft_print_unsigned(t_flag *flag, uintmax_t nb)
{
	if (flag->mod == h)
		return ((unsigned short)nb);
	else if (flag->mod == hh)
		return ((unsigned char)nb);
	else if (flag->mod == l)
		return ((unsigned long)nb);
	else if (flag->mod == ll)
		return ((unsigned long long)nb);
	else if (flag->mod == j)
		return (nb);
	else if (flag->mod == z)
		return ((size_t)nb);
	else
		return ((unsigned int)nb);
}
