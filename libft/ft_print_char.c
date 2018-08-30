/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:54:27 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/20 15:46:08 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_char(va_list *ap, t_flag *flag)
{
	size_t ret;

	if (flag->mod == l)
		return (ft_print_wchar(ap, flag));
	ret = 1;
	if (!flag->min && (flag->width > (int)ret))
		ret = ret + ft_print_opt(ret, flag->width, (flag->zero) ? '0' : ' ');
	ft_putchar(va_arg(*ap, int));
	if (flag->min && (flag->width > 1))
		ret = ret + ft_print_opt(ret, flag->width, ' ');
	return (ret);
}

int		ft_print_ch(va_list *ap, t_flag *flag)
{
	size_t ret;

	(void)ap;
	ret = 1;
	if (!flag->min && (flag->width > 1))
		ret = ret + ft_print_opt(ret, flag->width, (flag->zero) ? '0' : ' ');
	ft_putchar(flag->c);
	if (flag->min && (flag->width > 1))
		ret = ret + ft_print_opt(ret, flag->width, ' ');
	return (ret);
}

int		ft_print_pct(va_list *ap, t_flag *flag)
{
	size_t ret;

	(void)ap;
	ret = 1;
	if (!flag->min && (flag->width > 1))
		ret = ret + ft_print_opt(ret, flag->width, (flag->zero) ? '0' : ' ');
	ft_putchar('%');
	if (flag->min && (flag->width > 1))
		ret = ret + ft_print_opt(ret, flag->width, ' ');
	return (ret);
}
