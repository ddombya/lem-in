/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:17:49 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/17 12:18:02 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static int      check_is_last(t_map *var, int i)
{
	if (var->matrix[i][var->nb_room - 1])
	{
		var->path[++(var->index_path)] = i;
		var->path[++(var->index_path)] = var->nb_room - 1;
		return (1);
	}
	return (0);
}

static void     del_elem(t_map *var, int i, int path)
{
	var->matrix[var->cur_room][i] = 0;
	var->matrix[i][var->cur_room] = 0;
	if (path)
	{
		var->path[var->index_path] = -1;
		var->index_path--;
	}
}

static int      find_door(t_map *var, int r_index, int d_index)
{
	while (d_index < var->nb_room)
	{
		if (var->matrix[r_index][d_index])
			return (d_index);
		d_index++;
	}
	return (0);
}

static int      check_is_in_path(t_map *var, int r_index)
{
	int i;

	i = -1;
	while (var->path[++i] != -1)
	{
		if (var->path[i] == r_index)
			return (1);
	}
	return (0);
}

int				solve(t_map *var, int i)
{
	if (var->matrix[0][var->nb_room - 1])
	{
		var->path[++(var->index_path)] = var->nb_room - 1;
		return (1);
	}
	while ((i = find_door(var, var->cur_room, i)))
	{
		if (check_is_last(var, i))
			return (1);
		else if (check_is_in_path(var, i))
			del_elem(var, i, 0);
	}
	if (!(var->cur_room = find_door(var, var->cur_room, 0)))
	{
		if (!var->index_path || !var->cur_room)
			return (0);
		var->cur_room = var->path[var->index_path - 1];
		del_elem(var, var->path[var->index_path], 1);
		if (solve(var, 0))
			return (1);
	}
	var->path[++(var->index_path)] = var->cur_room;
	if (solve(var, 0))
		return (1);
	return (0);
}