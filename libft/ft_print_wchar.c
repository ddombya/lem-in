/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:39:15 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 17:16:41 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_print_wchar(va_list *ap, t_flag *flag)
{
	char	*str;
	size_t	len;
	size_t	len2;

	str = ft_wc_to_str(va_arg(*ap, wchar_t));
	len = ft_strlen(str);
	len2 = len;
	len = (len != 0) ? len : 1;
	if (!flag->min && (flag->width > (int)len))
		len = len + ft_print_opt(len, flag->width, (flag->zero) ? '0' : ' ');
	len2 ? ft_putstr(str) : write(1, "\0", 1);
	ft_strdel(&str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	return (len);
}
