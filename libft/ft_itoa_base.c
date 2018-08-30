/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:34:28 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:36:48 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char			*ft_itoa_base(uintmax_t n, int base)
{
	int			i;
	char		tab[65];
	uintmax_t	ret;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	i = 64;
	tab[i] = '\0';
	while (n)
	{
		ret = n % base;
		n /= base;
		if (base > 10 && ret > 9)
			tab[--i] = ret + 55;
		else
			tab[--i] = ret + '0';
	}
	return (ft_strdup(tab + i));
}

char			*ft_itoa_base_2(uintmax_t n, int base)
{
	int			i;
	char		tab[65];
	uintmax_t	ret;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	i = 64;
	tab[i] = '\0';
	while (n)
	{
		ret = n % base;
		n /= base;
		if (base > 10 && ret > 9)
			tab[--i] = ret + 87;
		else
			tab[--i] = ret + '0';
	}
	return (ft_strdup(tab + i));
}
