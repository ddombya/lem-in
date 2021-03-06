/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:02:06 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 12:02:35 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	return (0);
}
