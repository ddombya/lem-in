/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:24:11 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 17:16:20 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_print_u_int(va_list *ap, t_flag *flag)
{
	char		*str;
	size_t		len;
	uintmax_t	n;
	int			cmp;

	n = ft_print_unsigned(flag, va_arg(*ap, uintmax_t));
	if (n == 0 && flag->prc)
		str = ft_strnew(0);
	else
		str = ft_itoa_base(n, 10);
	cmp = ft_strcmp(str, "0");
	len = ft_strlen(str);
	ft_print_u_prc(&str, &len, flag);
	if (!flag->min && flag->prc_len < flag->width && flag->width > (int)len)
		len = len + ft_print_opt(len, flag->width, ' ');
	if (!(!cmp && flag->prc && flag->prc_len <= (int)len))
		ft_putstr(str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	ft_strdel(&str);
	return (len);
}
