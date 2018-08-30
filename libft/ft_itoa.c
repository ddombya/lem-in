/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:03:01 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:36:31 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static intmax_t		ft_abs(intmax_t nb)
{
	return (nb < 0 ? -nb : nb);
}

char				*ft_itoa(intmax_t c)
{
	char		str[25];
	int			i;
	intmax_t	nb;
	intmax_t	ret;

	if (c == 0)
		return (ft_strdup("0"));
	if (c == LLONG_MIN)
		c++;
	i = 24;
	nb = ft_abs(c);
	while (nb != 0)
	{
		ret = nb % 10;
		nb = nb / 10;
		str[--i] = ret + '0';
	}
	if (c < 0)
		str[--i] = '-';
	if (c == LLONG_MIN + 1)
		str[23]++;
	str[24] = '\0';
	return (ft_strdup(str + i));
}

char				*ft_u_itoa(uintmax_t c)
{
	char		*str;
	int			i;
	uintmax_t	nb;

	i = 1;
	if (c == 0)
		return (ft_strdup("0"));
	while (c /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i] = '\0';
	nb = ft_abs(c);
	while (i--)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
