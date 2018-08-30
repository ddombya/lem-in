/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:01:53 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/29 19:01:55 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void     algo_no_null(t_room *dst, t_room *src, int dist)
{
	t_room  	**tmp;
	int		*tmp1;
	int		i;

	tmp = dst->tab;
	tmp1 = dst->dist;
	i = 0;
	while (dst->tab[i] != NULL)
		i++;
	if (!(dst->tab = malloc(sizeof(t_room) * (i + 2))))
        return ;
	if (!(dst->dist = (int*)malloc(sizeof(int) * (i + 2))))
        return ;
	i = -1;
	while (tmp[++i])
	{
		dst->tab[i] = tmp[i];
		dst->dist[i] = tmp1[i];
	}
	free(tmp);
	tmp = NULL;
	free(tmp1);
	tmp1 = NULL;
	dst->tab[i] = src;
	dst->tab[i + 1] = NULL;
	dst->dist[i] = dist;
	dst->dist[i + 1] = -1;
}

static void	    algo_null(t_room *dst, t_room *src, int dist)
{
	if (!(dst->tab = malloc(sizeof(t_room) * 2)))
        return ;
	dst->tab[0] = src;
	dst->tab[1] = NULL;
	if (!(dst->dist = (int*)malloc(sizeof(int) * 2)))
        return ;
	dst->dist[0] = dist;
	dst->dist[1] = -1;
}

void		    dijkstra_new(t_room *dst, t_room *src, int dist)
{
	if (dst == NULL || src == NULL)
		return ;
	if (dst->tab == NULL && dst->dist == NULL)
		algo_null(dst, src, dist);
	else
		algo_no_null(dst, src, dist);
	ft_error();
}