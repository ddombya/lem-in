/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:08:49 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:35:20 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_char_to_str(char c)
{
	char	*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	ft_memset(str, c, 1);
	return (str);
}
