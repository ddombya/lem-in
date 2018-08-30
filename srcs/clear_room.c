/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:42:43 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/30 14:42:56 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void      clear_room(t_room *room)
{
    while (room)
    {
        room->tr = false;
        free(room->tab);
        room->tab = NULL;
        free(room->dist);
        room->dist = NULL;
        room = room->next;
    }
}