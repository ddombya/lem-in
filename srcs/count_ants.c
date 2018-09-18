/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:39:40 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 14:35:01 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		count_ants(t_map *var, char *line)
{
	char	*str;
	int		i;

	i = 0;
	var->start = 1;
	var->list_ants = strjoin(var->list_ants, line, 0);
	if (line[0] == '#')
		return ;
	str = ft_strtrim(line);
	if ((var->ants = ft_atoi(str)) <= 0)
		ft_exit(var, ERROR);
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
			ft_exit(var, ERROR);
		i++;
	}
}
