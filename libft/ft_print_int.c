/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:53:51 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/22 15:18:12 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char		*ft_print_nb(va_list *ap, t_flag *flag, char *sign)
{
	intmax_t	nb;
	uintmax_t	u_nb;

	*sign = '+';
	nb = ft_print_signed(flag, va_arg(*ap, intmax_t));
	if (nb < 0 && nb > LLONG_MIN)
	{
		u_nb = (uintmax_t)-nb;
		*sign = '-';
	}
	else
		u_nb = (uintmax_t)nb;
	if (u_nb == 0 && flag->prc)
		return (ft_strnew(0));
	return (ft_itoa(u_nb));
}

static void		ft_flag_plus(char *sign, t_flag *flag, int *len, char **str)
{
	char	*tmp;

	if (flag->plus || *sign == '-')
	{
		tmp = ft_strjoin((*sign == '-') ? "-" : "+", *str);
		ft_strdel(str);
		*str = tmp;
		(*len)++;
	}
	else if (flag->sp && **str != '-')
	{
		tmp = ft_strjoin(" ", *str);
		ft_strdel(str);
		*str = tmp;
		(*len)++;
	}
}

static int		ft_print_d(char *str, int len, t_flag *flag)
{
	char *tmp;

	tmp = str;
	ft_putchar('-');
	len += ft_print_opt(len, flag->width, '0');
	ft_putstr(tmp);
	ft_strdel(&str);
	return (len);
}

int				ft_print_int(va_list *ap, t_flag *flag)
{
	char	*str;
	int		len;
	char	sign;

	str = ft_print_nb(ap, flag, &sign);
	len = ft_strlen(str);
	flag->sign = (sign == '-') ? ft_atoi(str) : 0;
	ft_print_prc(&str, &sign, &len, flag);
	ft_flag_plus(&sign, flag, &len, &str);
	if (!flag->min && flag->prc_len < flag->width && flag->width > len)
	{
		if (flag->width > 9 && flag->zero)
		{
			if (flag->sign)
				return (ft_print_d(ft_itoa(flag->sign), len, flag));
			len += ft_print_opt(len, flag->width, '0');
		}
		len += ft_print_opt(len, flag->width, ' ');
	}
	if (!(!ft_strcmp(str, "0") && flag->prc && flag->prc_len <= len))
		ft_putstr(str);
	if (flag->min && (flag->width > 1))
		len = len + ft_print_opt(len, flag->width, ' ');
	ft_strdel(&str);
	return (len);
}
