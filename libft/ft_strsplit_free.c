/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:15:15 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 18:29:42 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_strsplit_free(void ***to_del)
{
	int i;

	i = 0;
	if (!to_del || !*to_del)
		return ;
	i = ft_strsplit_len((char **)*to_del);
	if (i > 0)
	{
		while (i >= 0)
		{
			ft_strdel((char **)&to_del[0][i]);
			i--;
		}
		free(*to_del);
		*to_del = NULL;
	}
}
