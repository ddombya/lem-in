/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:53:12 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/10 15:34:20 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_print_octal(va_list *ap, t_flag *flag)
{
	char		*str;
	size_t		len;
	uintmax_t	n;

	n = ft_print_unsigned(flag, va_arg(*ap, uintmax_t));
	str = ft_itoa_oct(n, (flag->hash && n != 0) ? 1 : 0);
	len = ft_strlen(str);
	(flag->prc && n != 0) ? ft_print_u_prc(&str, &len, flag) : 0;
	if (!flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, flag->zero ? '0' : ' ');
	if (flag->prc && !flag->prc_len && n == 0 && !flag->hash)
		(flag->width) ? ft_putchar(' ') : len--;
	else
		ft_putstr(str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	ft_strdel(&str);
	return (len);
}
