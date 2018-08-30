/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:44:36 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/21 12:49:53 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_args_engine(char **str, va_list *ap, t_flag *flag)
{
	if (*++*str == '\0')
		return (0);
	if (((*str) = ft_find_flags(str, flag)) == NULL)
		return (-1);
	if (((*str) = ft_find_width(str, flag, ap)) == NULL)
		return (-1);
	if (((*str) = ft_find_prc(str, flag, ap)) == NULL)
		return (-1);
	if (((*str) = ft_find_mod(str, flag)) == NULL)
		return (-1);
	if (((*str) = ft_find_conversion(str, flag)) == NULL)
		return (-1);
	return (0);
}

int			ft_exec_flag(va_list *ap, t_flag *flag)
{
	int (*key[13])(va_list *ap, t_flag *flag);

	key[0] = ft_print_char;
	key[1] = ft_print_wchar;
	key[2] = ft_print_int;
	key[3] = ft_print_octal;
	key[4] = ft_print_ptr;
	key[5] = ft_print_str;
	key[6] = ft_print_wstr;
	key[7] = ft_print_u_int;
	key[8] = ft_print_hexa2;
	key[9] = ft_print_hexa;
	key[10] = ft_print_pct;
	key[11] = ft_print_ch;
	key[12] = ft_print_bin;
	if ((flag->conv >= c) && (flag->conv <= ch))
		return (key[flag->conv](ap, flag));
	else if (flag->conv == 12)
		return (key[flag->conv](ap, flag));
	else
		return (0);
}

int			ft_print(const char *str, va_list *ap, int print)
{
	char	*pcent;
	t_flag	flag;

	flag.ret = 0;
	if (ft_strcmp(str, "%") == 0)
		return (0);
	if ((pcent = ft_strchr(str, '%')) == NULL)
	{
		ft_putstr(str);
		return (print + ft_strlen(str));
	}
	else if (pcent > str)
	{
		ft_putnstr(str, pcent - str);
		return (ft_print(pcent, ap, print + (pcent - str)));
	}
	else
	{
		ft_bzero(&flag, sizeof(flag));
		if ((flag.ret = ft_args_engine(&pcent, ap, &flag)))
			return (flag.ret);
		if ((flag.ret = ft_exec_flag(ap, &flag)) == -1)
			return (-1);
		return (ft_print(pcent, ap, print + flag.ret));
	}
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_print(format, &ap, 0);
	return (ret);
}
