/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:53:27 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/17 13:53:36 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void        header(t_map *var)
{
    int i;

    i = -1;
    ft_printf("\n\n");
    ft_printf("\t   ");
    while (++i < var->nb_room)
    {
        ft_printf(" %d", (i > 9) ? (i % 10) : i);
    }
    ft_printf("\n\n");
}

void                print_tab(t_map *var)
{
    int i;
    int j;

    header(var);
    i = -1;
    while (++i < var->nb_room)
    {
        ft_printf("\t%d   ", (i > 9) ? (i % 10) : i);
        j = -1;
        while (++j < var->nb_room)
        {
            ft_printf("%d ", var->matrix[i][j]);
        }
        ft_printf("\t\t[%d] -  ", i);
        ft_printf("%s\n", var->room[i]);
    }
    ft_printf("\n\n");
}