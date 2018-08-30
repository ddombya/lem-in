/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:01:25 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/30 14:54:45 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void	main_opt(int ac, char **av, t_main *elem)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strncmp(av[i], "-H", 2) && ft_strisdigit(av[i] + 2))
			(*elem).hex = ft_atoi(av[i] + 2);
		else if (ft_strequ(av[i], "-p"))
			(*elem).print_path = 1;
		else if (ft_strequ(av[i], "-h"))
		{
			ft_printf("AIDE\nNAME\n\tlem-in\nSYNOPSIS\n");
			ft_printf("\tlem-in [-h] [-Hnum] [-p] < [map]\n");
			ft_printf("DESCRIPTION\n\t-h\tdisplay this help.\n");
			ft_printf("\t-Hnum\tignore the number of ants in ");
			ft_printf("the map and use num for processing.\n");
			ft_printf("\t-p\tdisplay all path(s).\n\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_printf("%s: unrecognized option '%s'\n", av[0], av[i]);
			exit(EXIT_SUCCESS);
		}
	}
}

static void	path_print(t_main elem)
{
	int i;
	int size;

	i = 0;
	while (elem.path[i])
	{
		size = 0;
		while (elem.path[i][size])
			size++;
		ft_printf("path %d :\t", i + 1);
		while (--size >= 0)
		{
			if (size != 0)
				ft_printf("%s\t", elem.path[i][size]->name);
			else
				ft_printf("%s\n", elem.path[i][size]->name);
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	t_main	elem;

	init_main(&elem);
	errno = 0;
	if (ac > 1)
		main_opt(ac, av, &elem);
	read_map(&elem);
	create_path(&elem);
	ft_printf("%s", elem.file);
	if (elem.path && elem.path[0] && elem.start
			&& elem.end && elem.hex)
		print_lemin(&elem);
	if (elem.print_path == 1)
		path_print(elem);
	/*lem_pathfree(lem);
	lem_freelst(lem);
	lem_freemain(&lem);*/
	return (EXIT_SUCCESS);
}