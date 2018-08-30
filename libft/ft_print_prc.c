/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:21:32 by ddombya           #+#    #+#             */
/*   Updated: 2018/02/21 13:57:19 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_print_prc(char **str, char *sign, int *len, t_flag *f)
{
	char	*tmp;
	int		i;
	int		size;
	int		wth;

	i = 0;
	if ((f->prc_len > *len) || (f->zero && f->width > *len
				&& !f->min))
	{
		wth = (f->prc_len) ? f->prc_len : f->width;
		size = (f->prc) ? f->prc_len - *len : f->width - *len;
		tmp = ft_strnew((f->prc_len) ? f->prc_len : f->width);
		if (!f->prc && (*sign == '-' || (*sign == '+' && (f->sp
							|| f->plus))))
			size--;
		while (i < size)
			tmp[i++] = '0';
		size = 0;
		while (i < wth)
			tmp[i++] = str[0][size++];
		ft_strdel(str);
		*str = tmp;
		*len = ft_strlen(tmp);
	}
}

void		ft_print_u_prc(char **str, size_t *len, t_flag *f)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	size;
	unsigned int	wth;

	i = 0;
	if ((f->prc_len > (int)*len) || (f->zero && f->width > (int)*len && !f->min))
	{
		wth = (f->prc_len <= (int)*len) ? f->width : f->prc_len;
		if (f->prc_len <= (int)*len)
			tmp = ft_strnew(f->width);
		size = (f->prc_len <= (int)*len) ? f->width - (int)*len : f->prc_len - (int)*len;
		tmp = ft_strnew((f->prc_len) ? (f->prc_len) : f->width);
		if (f->min && (f->prc_len > (int)*len) && size > 0 && (f->width > 13))
			size = 0;
		while (i < size)
			tmp[i++] = '0';
		size = 0;
		while (i < wth)
			tmp[i++] = str[0][size++];
		tmp[i] = '\0';
		ft_strdel(str);
		*str = tmp;
		*len = ft_strlen(tmp);
	}
}
