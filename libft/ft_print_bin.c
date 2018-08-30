/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:27:35 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/07 15:47:25 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_bin(va_list *ap, t_flag *flag)
{
	char		*str;
	int			len;
	uintmax_t	n;

	n = ft_print_unsigned(flag, va_arg(*ap, uintmax_t));
	str = ft_itoa_bin(n, (flag->hash && n != 0) ? 1 : 0);
	len = ft_strlen(str);
	if (!flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, flag->zero ? '0' : ' ');
	if (flag->prc && !flag->prc_len && n == 0 && !flag->hash)
		flag->width ? ft_putchar(' ') : len--;
	else
		ft_putstr(str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	ft_strdel(&str);
	return (len);
}
