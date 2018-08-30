/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:22:05 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/07 13:23:49 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_print_ptr(va_list *ap, t_flag *flag)
{
	flag->hash = 1;
	flag->mod = l;
	return (ft_print_hexa2(ap, flag));
}
