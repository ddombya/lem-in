/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:16:07 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 15:20:04 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char			*ft_find_flags(char **str, t_flag *flag)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == ' '
			|| **str == '+')
	{
		if (**str == '#')
			flag->hash = 1;
		else if (**str == '0')
			flag->zero = 1;
		else if (**str == '-')
			flag->min = 1;
		else if (**str == ' ')
			flag->sp = 1;
		else if (**str == '+')
		{
			flag->plus = 1;
			flag->sp = 0;
		}
		(*str)++;
		return (ft_find_flags(str, flag));
	}
	return (*str);
}
