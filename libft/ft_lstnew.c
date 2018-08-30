/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:19:25 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 11:19:43 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list *fresh_link;

	fresh_link = (t_list *)malloc(sizeof(t_list));
	if (fresh_link == NULL)
		return (NULL);
	if (content == NULL)
	{
		fresh_link->content = NULL;
		fresh_link->content_size = 0;
	}
	else
	{
		fresh_link->content = (void *)malloc(sizeof(void) * content_size);
		fresh_link->content_size = content_size;
		ft_memcpy(fresh_link->content, content, content_size);
	}
	fresh_link->next = NULL;
	return (fresh_link);
}
