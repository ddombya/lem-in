/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:38:55 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:37:14 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa_oct(uintmax_t n, int flag)
{
	char	*tab;
	char	*ret;
	int		i;

	tab = ft_itoa_base(n, 8);
	if (!flag)
		return (tab);
	ret = ft_strnew(flag + ft_strlen(tab));
	ret[0] = (flag) ? '0' : '\0';
	i = 0;
	while (tab[i])
	{
		ret[i + 1] = tab[i];
		i++;
	}
	free(tab);
	return (ret);
}
