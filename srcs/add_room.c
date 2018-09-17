/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:54:47 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/15 15:54:57 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void     check_start_end(t_map *var, char **room, int end)
{
    if (end)
    {
        var->room[var->nb_room - 1] = ft_strdup(room[0]);
        (var->cmd[1])++;
        return ;
    }
    var->room[0] = ft_strdup(room[0]);
    (var->cmd[0])++;
}

static void     parse1(t_map *var, char **line, char **room, int end)
{
    if (++(var->cmd[end]) > 1)
    {
        //printf("ok\n");
        //printf("test = %s %s\n", line[0], room[0]);
        free_tab(var, room, 0);
        free_tab(var, line, ERROR); 
    }
}

static void     parse2(t_map *var, int i, char **room)
{
    int index;

    index = room_index(var, room[0], 0);
    if (index > 0 && i != index)
        ft_exit(var, ERROR);
    var->room[i] = ft_strdup(room[0]);
}

void            add_room(t_map *var)
{
    int     i;
    int     j;
    char    **line;
    char    **room;

    i = 0;
    j = 1;
    line = ft_strsplit(var->list_room, '\n');
    while (line[i] && j < var->nb_room)
    {
        //0printf("line[i] = %s\n", line[i]);
        //printf("line[i][0] = %c\n", line[i][0]);
        room = ft_strsplit(line[i], ' ');
        if (!ft_strcmp("##start", line[i]))
        {
            //printf("t1\n");
            parse1(var, line, room, 0);
        }
        else if (!ft_strcmp("##end", line[i]))
        {
            printf("t2\n");
            //parse1(var, line, room, ERROR);
        }
        else if (var->cmd[0] == 1 && line[i][0] != HASH)
        {
            //printf("t3\n");
            check_start_end(var, room, 0);
        }
        else if (var->cmd[1] == 1 && line[i][0] != HASH)
        {
            //printf("t4\n");
            check_start_end(var, room, ERROR);
        }
        else if (line[i][0] != HASH)
        {
            //printf("t5\n");
            parse2(var, j++, room);
        }
        free_tab(var, room, 0);
        i++;
    }
    free_tab(var, line, 0);
}