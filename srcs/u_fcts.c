/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_fcts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:39:27 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 14:52:17 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		free_tab(t_map *var, char **tab, int status)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	if (status)
		ft_exit(var, ERROR);
	tab = NULL;
}

void		ft_exit(t_map *var, int status)
{
	int i;

	i = -1;
	free(var->tube);
	free(var->list_room);
	free(var->list_ants);
	if (var->init_2)
	{
		free(var->path);
		free_tab(var, var->room, 0);
		while (++i < var->nb_room)
			free(var->matrix[i]);
		free(var->matrix);
	}
	free(var);
	if (status == ERROR)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
}
