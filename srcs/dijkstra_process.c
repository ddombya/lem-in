/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:02:03 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 19:02:12 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*
** 0 select the start room and mark active
** 1 update all rooms who are connected by tube from the active room
** 2 search the non active room with the smallest distance in the table
** 3 select this room
** 4 replay from 1
*/

static void	    dijkstra_min(t_room *tmp, t_room **r_min, int *l, int *min)
{
	int i;

	if (tmp->tr == false && tmp->active == true
			&& tmp->tab != NULL && tmp->tab[0] != NULL)
	{
		if (!*l)
		{
			*min = tmp->dist[0];
			*r_min = tmp;
			*l = *l + 1;
		}
		i = 0;
		while (tmp->tab[i])
		{
			if (tmp->dist[i] < *min)
			{
				*min = tmp->dist[i];
				*r_min = tmp;
			}
			i++;
		}
	}
}

void		    dijkstra_process(t_room *start, t_room *ant_room, int dist)
{
	static int	j;
	int			l;
	int			min;
	t_room		*r_min;
	t_room		*tmp;

	r_min = NULL;
	if (j++ == 0)
		dijkstra_new(start, start, 0);
	tmp = start;
	tmp->tr = true;
	l = -1;
	while (tmp && tmp->tube[++l])
		dijkstra_new(lst_search(ant_room, tmp->tube[l]), tmp, dist + 1);
	tmp = ant_room;
	l = 0;
	while (tmp)
	{
		dijkstra_min(tmp, &r_min, &l, &min);
		tmp = tmp->next;
	}
	if (l != 0)
		dijkstra_process(r_min, ant_room, min);
}