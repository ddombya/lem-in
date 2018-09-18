/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:41:37 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 15:02:12 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_map		*map_init(void)
{
	t_map *var;

	var = (t_map*)ft_memalloc(sizeof(t_map));
	var->room = NULL;
	var->list_room = ft_strnew(1);
	var->list_ants = ft_strnew(1);
	var->tube = ft_strnew(1);
	var->nb_room = 0;
	var->ants = 0;
	var->start = 0;
	var->cur_room = 0;
	var->index_path = 0;
	var->matrix = NULL;
	var->cmd[0] = 0;
	var->cmd[1] = 0;
	var->path = NULL;
	var->init_2 = 0;
	return (var);
}

t_map		*map_init2(t_map *var)
{
	int i;
	int j;

	i = -1;
	j = -1;
	var->init_2 = 1;
	var->path = (int*)ft_memalloc(sizeof(int) * 2048);
	var->matrix = (int**)ft_memalloc(sizeof(int*) * var->nb_room);
	var->room = (char**)ft_memalloc(sizeof(char*) * (var->nb_room + 1));
	while (++i < var->nb_room)
	{
		var->path[i] = -1;
		var->room[i] = NULL;
		var->matrix[i] = (int*)ft_memalloc(sizeof(int) * var->nb_room);
		while (var->matrix[i][++j])
			var->matrix[i][j] = 0;
	}
	var->room[i] = NULL;
	var->path[0] = 0;
	return (var);
}
