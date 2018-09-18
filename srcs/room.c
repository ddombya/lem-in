/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:59:52 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 14:38:17 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void		check_is_number(t_map *var, char **room, char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || ft_isdigit(str[0]))
	{
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				free_tab(var, room, ERROR);
			i++;
		}
	}
	else
		free_tab(var, room, ERROR);
}

static void		valid_room(t_map *var, char *line)
{
	char **room;

	room = ft_strsplit(line, ' ');
	if (room[0][0] == 'L' || room[3])
		free_tab(var, room, ERROR);
	check_is_number(var, room, room[1]);
	check_is_number(var, room, room[2]);
	free_tab(var, room, 0);
}

int				room_index(t_map *var, char *name, int start)
{
	int i;

	i = start ? -1 : 0;
	while (var->room[++i] && i < var->nb_room)
	{
		if (!ft_strcmp(var->room[i], name))
			return (i);
	}
	return (i);
}

void			room(t_map *var, char *line)
{
	var->start = 2;
	var->list_room = strjoin(var->list_room, line, 0);
	if (line[0] == '#')
		return ;
	valid_room(var, line);
	var->nb_room++;
}
