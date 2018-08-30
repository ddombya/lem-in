/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddombya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:16:55 by ddombya           #+#    #+#             */
/*   Updated: 2017/11/07 11:19:02 by ddombya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*link;
	t_list	*fresh_link;
	t_list	*tmp;

	tmp = f(lst);
	link = ft_lstnew(tmp->content, tmp->content_size);
	if (link == NULL)
		return (NULL);
	fresh_link = link;
	while (lst->next != NULL)
	{
		tmp = f(lst->next);
		if (!(link->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		link = link->next;
		lst = lst->next;
	}
	return (fresh_link);
}
