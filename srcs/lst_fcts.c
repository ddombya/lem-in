/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:52:27 by ddombya           #+#    #+#             */
/*   Updated: 2018/08/28 16:16:28 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_room		*init_room(char *name, int x, int y)
{
	t_room	*elem;

	errno = 0;
	if (!(elem = malloc(sizeof(t_room))))
		return (NULL);
	elem->name = ft_strdup(name);
	ft_error();
	elem->next = NULL;
	elem->x = x;
	elem->y = y;
	elem->tube = NULL;
	elem->tr = false;
	elem->active = true;
	elem->tab = NULL;
	elem->hex = -1;
	elem->dist = NULL;
	return (elem);
}

t_room		*lst_add(t_room **alst, t_room *new)
{
	t_room	*tmp;

	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp && tmp->next && new)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_room		*lst_search(t_room *elem, char *name)
{
	while (elem)
	{
		if (ft_strequ(elem->name, name))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

static void	lst_pipe_fct(char **tube, t_room *tmp)
{
	char	**str;
	int		i;
	int		j;

	str = tmp->tube;
	i = 0;
	while (tmp->tube[i])
	{
		if (ft_strequ(tmp->tube[i], tube[1]))
			return ;
		i++;
	}
	if (!(tmp->tube = (char**)malloc(sizeof(char*) * (i + 2))))
		return ;
	j = 0;
	while (j < i)
	{
		tmp->tube[j] = str[j];
		j++;
	}
	tmp->tube[j] = ft_strdup(tube[1]);
	tmp->tube[i + 1] = NULL;
	free(str);
	str = NULL;
}

void		lst_pipe(t_room *elem, char **tube, bool b)
{
	t_room	*tmp;
	char	*tmp2;

	if ((tmp = lst_search(elem, tube[0])) != NULL)
	{
		if (tmp->tube == NULL)
		{
			if ((tmp->tube = (char**)malloc(sizeof(char*) * 2)) == NULL)
				return ;
			tmp->tube[0] = ft_strdup(tube[1]);
			tmp->tube[1] = NULL;
		}
		else
			lst_pipe_fct(tube, tmp);
	}
	if (b == true)
	{
		tmp2 = tube[1];
		tube[1] = tube[0];
		tube[0] = tmp2;
		lst_pipe(elem, tube, false);
	}
}