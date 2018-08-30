/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:05:25 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/12 12:34:22 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_print_hexa(va_list *ap, t_flag *flag)
{
	char		*str;
	size_t		len;
	uintmax_t	n;
	int			cmp;

	n = ft_print_unsigned(flag, va_arg(*ap, uintmax_t));
	str = ft_itoa_base(n, 16);
	cmp = ft_strncmp(str, "0\0", 2);
	len = (flag->prc && !flag->prc_len && n == 0) ? 0 : ft_strlen(str);
	(flag->prc) ? ft_print_u_prc(&str, &len, flag) : 0;
	if (flag->hash && cmp)
		len = len + 2;
	if (cmp && flag->hash && flag->zero && n > 0)
		ft_putstr("0X");
	if (!flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, flag->zero ? '0' : ' ');
	if (cmp && flag->hash && flag->hash && !flag->zero && n > 0)
		ft_putstr("0X");
	(flag->prc && !flag->prc_len && n == 0) ? 0 : ft_putstr(str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	ft_strdel(&str);
	return (len);
}

int			ft_print_hexa2(va_list *ap, t_flag *flag)
{
	char		*str;
	size_t		len;
	uintmax_t	n;
	int			cmp;

	n = ft_print_unsigned(flag, va_arg(*ap, uintmax_t));
	str = ft_itoa_base_2(n, 16);
	cmp = ft_strncmp(str, "0\0", 2);
	len = (flag->prc && !flag->prc_len && n == 0) ? 0 : ft_strlen(str);
	(flag->prc) ? ft_print_u_prc(&str, &len, flag) : 0;
	if ((flag->hash && cmp) || flag->conv == p)
		len = len + 2;
	if ((cmp && flag->hash && flag->zero && n > 0)
			|| (flag->conv == p && flag->zero))
		ft_putstr("0x");
	if (!flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, flag->zero ? '0' : ' ');
	if ((cmp && flag->hash && !flag->zero && n > 0)
			|| (flag->conv == p && !flag->zero))
		ft_putstr("0x");
	(flag->prc && !flag->prc_len && n == 0) ? 0 : ft_putstr(str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	ft_strdel(&str);
	return (len);
}
