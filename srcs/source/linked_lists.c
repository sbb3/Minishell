/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:37:59 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/13 02:45:56 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source_.h"

int	list_component_size(t_component *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
