/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:44:41 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/14 22:21:54 by herve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdbool.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define START 1
# define END 2
# define BUFSIZE 1
# define ERROR 6
# define HASH 35

typedef struct	s_map
{
	char		**room;
	char		*list_room;
	char		*list_ants;
	char		*links;
	int			nb_room;
	int			ants;
	int			start;
	int			cur_room;
	int			index_path;
	int			*path;
	int			**matrix;
	int			boolean[2];
	int			nl;
	int			init_2;
}				t_map;
/*typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	char			**tube;
	bool			tr;
	bool			active;
	int				*dist;
	int				hex;
	struct s_room	**tab;
	struct s_room	*next;
}					t_room;

typedef struct		s_main
{
	int				hex;
	int				print_path;
	char			*file;
	t_room			*ant_room;
	t_room			*start;
	t_room			*end;
	t_room			***path;
	bool			room;
	bool			tube;
}					t_main;


t_room			*init_room(char *str, int x, int y);
t_room			*lst_add(t_room **alst, t_room *new);
t_room			*lst_search(t_room *elem, char *name);
void			lst_pipe(t_room *elem, char **tube, bool b);

void			read_map(t_main *elem);

void			init_main(t_main *elem);

void			create_path(t_main *elem);
void		    dijkstra_new(t_room *dst, t_room *src, int dist);
void		    dijkstra_process(t_room *start, t_room *ant_room, int dist);
void			print_path(t_room *end, t_room *start, t_room ***path);
void			print_display(t_main *elem, int max, bool *print, int nb_path);
void			print_lemin(t_main *elem);

void      		clear_room(t_room *room);

//char			**parse_room_format(char *line);
//int			parse_comment(char *line);*/
#endif
