/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:22:02 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 18:33:00 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*static int	read_map_room(t_main *elem, char *line, char **cmd)
{
	int		i;
	char	**split;
	t_room	*room;

	elem->room = true;
	split = ft_strsplit(line, ' ');
	i = ft_strsplit_len(split);
	if (elem->tube == true || i != 3 || !ft_strisalnum(split[0])
			|| !ft_strisdigit(split[1]) || !ft_strisdigit(split[2]))
	{
		ft_strsplit_free((void ***)&split);
		return (-1);
	}
	room = init_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
	lst_add(&elem->ant_room, room);
	if (*cmd)
	{
		if (ft_strequ(*cmd, "##start"))
			elem->start = room;
		if (ft_strequ(*cmd, "##end"))
			elem->end = room;
		ft_strdel(cmd);
	}
	ft_strsplit_free((void ***)&split);
	return (0);
}

static int	read_map_pipe(t_main *elem, char *line)
{
	int		i;
	char	**split;

	elem->tube = true;
	split = ft_strsplit(line, '-');
	i = ft_strsplit_len(split);
	if (elem->room == false || i != 2 || !ft_strisalnum(split[0])
			|| !ft_strisalnum(split[1]))
	{
		ft_strsplit_free((void ***)&split);
		return (-1);
	}
	lst_pipe(elem->ant_room, split, true);
	ft_strsplit_free((void ***)&split);
	return (0);
}

static void	read_map_end(t_main *elem, char **line)
{
	char	*tmp;

	tmp = elem->file;
	elem->file = ft_strjoin(elem->file, *line);
	ft_strdel(&tmp);
	ft_strdel(line);
	tmp = elem->file;
	elem->file = ft_strjoin(elem->file, "\n");
	ft_strdel(&tmp);
	ft_error();
}

static int	read_map_while(t_main *elem, char *line, int index)
{
	static char	*cmd;

	if (ft_strlen(line) == 0 || (index > 0 && elem->hex < 1))
		return (-1);
	if (index == 0 && ft_strisdigit(line) && elem->hex == -1)
		elem->hex = ft_atoi(line);
	else if (index == 0 && ft_strisdigit(line))
		return (0);
	else if (!ft_strncmp(line, "##", 2) && (ft_strequ(line, "##start")
				|| ft_strequ(line, "##end")))
		cmd = ft_strdup(line);
	else if (line[0] != '#' && line[0] != 'L' && !ft_strchr(line, '-')
			&& !ft_strchr(line, '.') && !ft_strchr(line, ',')
			&& ft_countchar(line, ' ') == 2)
		return (read_map_room(elem, line, &cmd));
	else if (!ft_strncmp(line, "#", 1))
		return (2);
	else if (ft_strchr(line, '-') && ft_countchar(line, '-') == 1)
		return (read_map_pipe(elem, line));
	else
		return (-1);
	ft_error();
	return (0);
}

void		read_map(t_main *elem)
{
	int		i;
	int		brk;
	char	*line;

	errno = 0;
	line = NULL;
	i = 0;
	while (get_next_line(0, &line))
	{
		brk = read_map_while(elem, line, i);
		//printf("%s\n", line);
		if (brk == -1)
		{
			ft_strdel(&line);
			break ;
		}
		read_map_end(elem, &line);
		if (brk != 2)
			i++;
	}
	if (elem->hex < 1 || elem->start == NULL || elem->end == NULL
			|| elem->room == false || elem->tube == false)
	{
		printf("elem->hex = %d\n", elem->hex);
		//printf("elem->start = %s\n", elem->start->name);
		//printf("elem->end = %s\n", elem->end->name);
		printf("elem->room = %d\n", elem->room);
		printf("elem->tube = %d\n", elem->tube);
		ft_printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
}*/
static int	parse_room(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return ((i == (int)ft_strlen(str)) ? 1 : 0);
}

void		read_map(t_map *var)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!var->ants)
			count_ants(var, line);
		else if (ft_strchr(line, '-') || var->start == 3)
			tube(var, line);
		else if ((var->start == 1 || var->start == 2) && !parse_room(line))
			room(var, line);
		else
			ft_exit(var, ERROR);
	}
	if (!var->ants || !var->tube[0])
		ft_exit(var, ERROR);
	var = map_init2(var);
}

int			main(void)
{
	t_map *test;
	int	i;

	test = map_init();
	i = 0;
	read_map(test);
	add_room(test);
	if (!test->START || !test->END)
	{
		ft_printf("error1\n");
		ft_exit(test, ERROR);
	}
	create_tab(test);
	//print_tab(test);
	if (solve(test, 0))
		solve_handler(test);
	else
	{
		ft_printf("error2\n");
		ft_exit(test, ERROR);
	}
	ft_exit(test, 0);
}
