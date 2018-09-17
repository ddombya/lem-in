/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:04:35 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/17 13:04:48 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void		valid_tube(t_map *var, char *tube)
{
	char **t;

	t = ft_strsplit(tube, '-');
	if (t[2])
		free_tab(var, t, ERROR);
	free_tab(var, t, 0);
}

void			create_tab(t_map *var)
{
	int		i;
	int		room_1;
	int		room_2;
	char	**tube;
	char	**t;

	i = -1;
	tube = ft_strsplit(var->tube, '\n');
	while (tube[++i])
	{
		printf("%s\n", tube[i]);
		if (tube[i][0] == '#')
			continue ;
		valid_tube(var, tube[i]);
		t = ft_strsplit(tube[i], '-');
		if ((room_1 = room_index(var, t[0], 1)) >= var->nb_room ||
			(room_2 = room_index(var, t[1], 1)) >= var->nb_room)
		{
			free_tab(var, t, 0);
			free_tab(var, tube, ERROR);
		}
		room_1 ? (var->matrix[room_2][room_1] = 1) : 0;
		room_2 ? (var->matrix[room_1][room_2] = 1) : 0;
		free_tab(var, t, 0);
		//i++;
	}
	free_tab(var, tube, 0);
}