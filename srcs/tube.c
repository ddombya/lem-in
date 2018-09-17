/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:42:52 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/15 15:43:06 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		tube(t_map *var, char *line)
{
	if (var->start == 2)
		var->start = 3;
	if (var->start != 3)
		ft_exit(var, ERROR);
	var->tube = strjoin(var->tube, line, 0);
}