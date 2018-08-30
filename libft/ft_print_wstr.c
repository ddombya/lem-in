/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:47:25 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 17:17:18 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char		*ft_ws_to_str(wchar_t *wstr)
{
	char	*str;
	int		i;

	if (!wstr)
		return (NULL);
	i = 0;
	str = ft_strnew(0);
	while (wstr[i])
		str = ft_strjoin_free(str, ft_wc_to_str(wstr[i++]), 3);
	return (str);
}

static char		*ft_wstrnew(wchar_t *wstr, size_t len)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	if (!wstr)
		return (NULL);
	str = ft_strnew(0);
	str2 = NULL;
	while (wstr[i] && ft_strlen(str) <= len)
	{
		ft_strdel(&str2);
		str2 = ft_strdup(str);
		str = ft_strjoin(str, ft_wc_to_str(wstr[i]));
		i++;
	}
	ft_strdel(&str);
	return (str2);
}

int				ft_print_wstr(va_list *ap, t_flag *flag)
{
	wchar_t		*wstr;
	char		*str;
	size_t		len;
	size_t		len2;

	wstr = va_arg(*ap, wchar_t *);
	if (flag->prc_len && flag->prc)
		str = ft_wstrnew(wstr, flag->prc_len);
	else
		str = ft_ws_to_str(wstr);
	str = (!str) ? ft_strdup("(null)") : str;
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
