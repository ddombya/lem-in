#include "includes/lem-in.h"

void		ft_exit(t_map *var, int status)
{
	int i;

	i = -1;
	free(var->links);
	free(var->list_room);
	free(var->list_ants);
	if (var->init_2)
	{
		free(var->path);
		//
		while (++i < var->nb_room)
			free(var->matrix[i]);
		free(var->matrix);
	}
	free(var);
	if (status == ERROR)
	{
		ft_putstr_fd("error\n", 2);
		exit(1);
	}
}
