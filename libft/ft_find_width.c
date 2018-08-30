/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:53:36 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 15:21:48 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_find_width(char **str, t_flag *flag, va_list *ap)
{
	if (**str == '*' || DIGIT(**str))
	{
		if (DIGIT(**str))
		{
			flag->width = ft_atoi(*str);
			(*str)++;
		}
		else
		{
			flag->width = va_arg(*ap, int);
			(*str)++;
		}
	}
	return (*str);
}
