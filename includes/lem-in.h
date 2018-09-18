/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:44:41 by ddombya           #+#    #+#             */
/*   Updated: 2018/09/18 17:45:02 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdbool.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define START cmd[0]
# define END cmd[1]
# define BUFSIZE 1
# define ERROR 1
# define HASH '#'
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define CYAN "\033[36m"
# define GREY "\033[37m"
# define NOCOLOR "\033[0m"

typedef struct	s_map
{
	char		**room;
	char		*list_room;
	char		*list_ants;
	char		*tube;
	int			nb_room;
	int			ants;
	int			start;
	int			cur_room;
	int			index_path;
	int			*path;
	int			**matrix;
	int			cmd[2];
	int			nl;
	int			init_2;
}				t_map;

void			free_tab(t_map *var, char **tab, int status);
void			ft_exit(t_map *var, int status);

void			count_ants(t_map *var, char *line);
void			room(t_map *var, char *line);
void			tube(t_map *var, char *line);

int				room_index(t_map *var, char *name, int start);

t_map			*map_init(void);
t_map			*map_init2(t_map *var);

void			add_room(t_map *var);
void			create_tab(t_map *var);
void			print_tab(t_map *var);
void			solve_handler(t_map *var);

int				solve(t_map *var, int i);


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
