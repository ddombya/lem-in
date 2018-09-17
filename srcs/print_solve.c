/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:07:32 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/17 14:07:41 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static int     print_ant(char *room, int ant)
{
    return (ft_printf("L%d-%s \n", ant, room));
}

static void     print_solve(t_map *var, int n)
{
    int ants;

    if (n == (var->index_path + var->ants + 1))
        return ;
    ants = var->ants + 1;
    while (--ants > 0)
    {
        if (n - ants > 0 && (n - ants) <= var->index_path)
            print_ant(var->room[var->path[n - ants]], ants);
    }
    print_solve(var, ++n);
}

void            solve_handler(t_map *var)
{
    int i;

    i = 1;
    ft_printf("%s\n", var->list_ants);
    ft_printf("%s\n", var->list_room);
    ft_printf("%s\n\n", var->tube);
    while (++i <= var->index_path)
    {
        ft_printf("[%d]", var->path[i]);
        if (i != var->index_path)
            ft_printf("-");
    }
    ft_printf("\n\n");
    print_solve(var, 2);
}