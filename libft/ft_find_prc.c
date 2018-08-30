/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_prc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:36:09 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 15:20:39 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_find_prc(char **str, t_flag *flag, va_list *ap)
{
	if (**str == '.' || DIGIT(**str))
	{
		flag->prc = 1;
		if (DIGIT(**str))
		{
			flag->prc_len = (flag->prc_len * 10) + ((**str) - '0');
			(*str)++;
			(*str) = ft_find_prc(str, flag, ap);
		}
		else
		{
			(*str)++;
			flag->prc_len = 0;
			*str = ft_find_prc(str, flag, ap);
		}
	}
	return (*str);
}
