/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem-in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:14:39 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/30 13:36:09 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static int	print_one_direct_start_to_end(t_main *elem)
{
	int i;
	int j;

	j = 0;
	while (elem->path[0][j])
		j++;
	if (j == 2 && elem->path[0][0] == elem->end && elem->path[0][1] == elem->start)
	{
		i = 0;
		while (++i <= elem->hex)
			ft_printf("L%d-%s ", i, elem->end->name);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

static void	print_process(t_main *elem, int nb_path, int *endhex)
{
	int i;
	int j;

	i = 0;
	while (i < nb_path)
	{
		j = 0;
		while (elem->path[i][++j])
		{
			if (elem->path[i][j] == elem->start && elem->start->hex == -1)
				elem->start->hex = 1;
			else if (elem->path[i][j] == elem->start
					&& elem->path[i][j - 1]->hex == -1)
				elem->start->hex++;
			else if (elem->path[i][j] == elem->start)
				elem->start->hex = elem->path[i][j - 1]->hex + nb_path;
			if (elem->path[i][j]->hex != -1)
			{
				elem->path[i][j - 1]->hex = elem->path[i][j]->hex;
				if (j == 1)
					(*endhex)++;
			}
		}
		i++;
	}
}

static int  print_max(t_main *elem)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (elem->path[i] && max < elem->hex)
	{
		j = -1;
		while (elem->path[i][++j] && max < elem->hex)
		{
			if (max < elem->path[i][j]->hex && elem->path[i][j] != elem->start
					&& elem->path[i][j]->hex <= elem->hex)
				max = elem->path[i][j]->hex;
		}
		i++;
	}
	return (max);
}

void		print_display(t_main *elem, int max, bool *print, int nb_path)
{
	int		i[3];

	i[1] = 0;
	i[2] = 1;
	while (i[2] <= max)
	{
		i[0] = 0;
		while (elem->path[i[0]] && i[2] <= max)
		{
			i[1] = -1;
			while (elem->path[i[0]][++i[1]] && i[2] <= max)
				if (i[2] == elem->path[i[0]][i[1]]->hex
						&& elem->path[i[0]][i[1]] != elem->start)
				{
					ft_printf("L%d-%s ", elem->path[i[0]][i[1]]->hex,
							elem->path[i[0]][i[1]]->name);
					*print = true;
				}
			i[0]++;
		}
		if (i[0] == nb_path && elem->path[i[0] - 1][i[1] - 1] == elem->start)
			i[2]++;
	}
}

void	print_reinitialize(t_main *elem)
{
	int		i;
	t_room	*tmp;

	i = 0;
	while (elem->path[i])
	{
		if (elem->path[i][0])
		{
			tmp = init_room(elem->path[i][0]->name, 0, 0);
			elem->path[i][0] = tmp;
		}
		i++;
	}
}

void		print_lemin(t_main *elem)
{
	int		nb_path;
	int		max;
	int		endhex;
	bool	print;

	elem->start->hex = -1;
	print = false;
	nb_path = 0;
	endhex = 0;
	while (elem->path[nb_path])
		nb_path++;
	if (nb_path == 1 && print_one_direct_start_to_end(elem))
		return ;
	print_reinitialize(elem);
	while (endhex <= elem->hex)
	{
		print = false;
		print_process(elem, nb_path, &endhex);
		max = print_max(elem);
		print_display(elem, max, &print, nb_path);
		if (print == true)
			ft_putchar('\n');
	}
}
