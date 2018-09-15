#include "includes/lem-in.h"

void		count_ants(t_map *var, char *line)
{
	char	*str;
	int		i;

	i = 0;
	var->start = 1;
	var->list_ants = ft_strjoin(var->list_ants, line);
	if (line[0] == HASH)
		return ;
	str = ft_strtrim(line);
	if ((var->ants = ft_atoi(str)) <= 0)
		ft_exit(var, ERROR);
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i++]))
			ft_exit(var, ERROR);
	}
}
