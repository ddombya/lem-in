/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:56:45 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 18:56:54 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void     dij_create_path(t_main *elem)
{
	int i;
	int j;

	i = 0;
	while (elem->start->tube && elem->start->tube[i])
		i++;
	if (!(elem->path = malloc(sizeof(t_main) * (i + 1))))
        return (ft_error());
	j = 0;
	while (j < (i + 1))
	{
		elem->path[j] = NULL;
		j++;
	}
	j = 0;
	while (j < i)
	{
		dijkstra_process(elem->start, elem->ant_room, 0);
		print_path(elem->end, elem->start, &(elem->path[j]));
		clear_room(elem->ant_room);
		j++;
	}
}

static void	    check_create_path(t_main *elem)
{
	int i;
	int j;
	int size;

	i = 0;
	while (elem->path[i])
	{
		j = 0;
		while (elem->path[i] && elem->path[i][j])
			j++;
		if (i == 0)
			size = j;
		if ((size == 2 && elem->path[0][0] == elem->end
					&& elem->path[0][1] == elem->start && i > 0)
				|| (j >= 2 * size))
		{
			free(elem->path[i]);
			free(elem->path[i + 1]);
			elem->path[i] = NULL;
			elem->path[i + 1] = NULL;
			break ;
		}
		i++;
	}
}

void			create_path(t_main *elem)
{
	int j;

	dij_create_path(elem);
	j = 0;
	while (elem->path[j])
		j++;
	if (!j)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	check_create_path(elem);
}