/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:18:05 by ddombya           #+#    #+#             */
/*   Updated: 2017/12/07 11:04:20 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static t_gnl		*gnl_lstnew(int fd)
{
	t_gnl	*buffer;

	buffer = (t_gnl *)malloc(sizeof(*buffer));
	buffer->content = ft_memalloc(1);
	buffer->ret = 1;
	buffer->fd = fd;
	buffer->next = NULL;
	return (buffer);
}

static t_gnl		*gnl_push_elem(t_gnl *buffer, int fd)
{
	t_gnl	*elem;

	if (!buffer)
		return (NULL);
	while (buffer)
	{
		if (buffer->fd == fd)
			break ;
		if (buffer->next == NULL)
		{
			elem = gnl_lstnew(fd);
			buffer->next = elem;
			return (elem);
		}
		buffer = buffer->next;
	}
	return (buffer);
}

static int			ft_read_line(t_gnl **buffer, char **line)
{
	char		*str;

	str = ft_strchr((*buffer)->content, '\n');
	if (str != NULL)
	{
		*line = ft_strsub((*buffer)->content, 0, (str - (*buffer)->content));
		ft_memcpy((*buffer)->content, str + 1, ft_strlen(str));
		str = NULL;
		return (1);
	}
	return (0);
}

static int			ft_read_buf(t_gnl **buffer, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	while (((*buffer)->ret = read((*buffer)->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[(*buffer)->ret] = '\0';
		tmp = ft_strjoin((*buffer)->content, buf);
		ft_strdel(&(*buffer)->content);
		(*buffer)->content = tmp;
		if (ft_read_line(buffer, line) == 1)
			return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*str;
	t_gnl			*buffer;

	if (!str)
		str = gnl_lstnew(fd);
	buffer = gnl_push_elem(str, fd);
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if ((ft_read_buf(&buffer, line) == 1))
		return (1);
	if (buffer->ret == -1)
		return (-1);
	if (ft_strlen(buffer->content) == 0)
		return (0);
	if (ft_read_line(&buffer, line) == 1)
		return (1);
	*line = ft_strdup(buffer->content);
	ft_strclr(buffer->content);
	return (1);
}
