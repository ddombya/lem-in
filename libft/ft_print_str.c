/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:16:55 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/20 13:16:48 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_str(va_list *ap, t_flag *flag)
{
	char	*str;
	size_t	len;
	size_t	len2;

	if (flag->mod == l)
		return (ft_print_wstr(ap, flag));
	str = va_arg(*ap, char *);
	str = (!str) ? ft_strdup("(null)") : ft_strdup(str);
	len = ft_strlen(str);
	if (flag->prc && flag->prc_len && flag->prc_len < (int)len)
		len = flag->prc_len;
	len2 = len;
	if (!flag->min && (flag->width > (int)len))
		len = len + ft_print_opt(len, flag->width, (flag->zero) ? '0' : ' ');
	ft_putnstr(str, len2);
	ft_strdel(&str);
	if (flag->min && (flag->width > (int)len))
		len = len + ft_print_opt(len, flag->width, ' ');
	return (len);
}
