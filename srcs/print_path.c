/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:58:02 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/30 11:58:11 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void     print_malloc(t_room ***path, int i)
{
	t_room	**tmp;
	int		j;

	j = 0;
	if (!i)
    {
		if (!(path[0] = malloc(sizeof(t_room) * (i + BUFSIZE + 1))))
            return ;
    }
	else
	{
		tmp = path[0];
		if (!(path[0] = malloc(sizeof(t_room) * (i + BUFSIZE + 1))))
            return ;
		while (j < i)
		{
			path[0][j] = tmp[j];
			j++;
		}
		free(tmp);
		tmp = NULL;
	}
	while (j <= i + BUFSIZE)
	{
		path[0][j] = NULL;
		j++;
	}
}

static void     print_min(t_room *tmp, t_room **r_min, int *min)
{
	int i;

	i = 1;
	while (tmp->tab[i])
	{
		if (tmp->dist[i] <= *min && tmp->tab[i]->active == true)
		{
			*min = tmp->dist[i];
			*r_min = tmp->tab[i];
		}
		i++;
	}
}

static void     print_end(t_room **r_min, int *count, t_room ***path)
{
	if ((*count % BUFSIZE) == 0)
		print_malloc(path, *count);
	path[0][*count] = *r_min;
	*count = 0;
}

void		print_path(t_room *end, t_room *start, t_room ***path)
{
	static int	count;
	int			min;
	t_room		*r_min;
	t_room		*tmp;

	tmp = end;
	if (!tmp || !tmp->dist || !tmp->tab)
		return ;
	min = tmp->dist[0];
	r_min = tmp->tab[0];
	if ((count % BUFSIZE) == 0)
		print_malloc(path, count);
	path[0][count] = tmp;
	print_min(tmp, &r_min, &min);
	count++;
	if (r_min != start && r_min->active == true)
	{
		r_min->active = false;
		print_path(r_min, start, path);
	}
	else if (r_min->active == true)
		print_end(&r_min, &count, path);
}