/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:51:10 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 18:52:30 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*next;

	list = *lst;
	while (list->next)
	{
		next = list->next;
		ft_lstdelone(list, del);
		list = next;
	}
	ft_lstdelone(list, del);
	*lst = NULL;
}
