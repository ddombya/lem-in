/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:53:27 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 18:11:04 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void		header(t_map *var)
{
	int i;

	i = 0;
	ft_printf("\n\n");
	ft_printf("\t   ");
	while (i < var->nb_room)
	{
		ft_printf(" %d", (i > 9) ? (i % 10) : i);
		i++;
	}
	ft_printf("\n\n");
}

void			print_tab(t_map *var)
{
	int i;
	int j;

	header(var);
	i = 0;
	while (i < var->nb_room)
	{
		ft_printf("\t%d   ", (i > 9) ? (i % 10) : i);
		j = 0;
		while (j < var->nb_room)
		{
			ft_printf("%d ", var->matrix[i][j]);
			j++;
		}
		ft_printf("\t\t[%d] -  ", i);
		ft_printf("%s\n", var->room[i]);
		i++;
	}
	ft_printf("\n\n");
}
