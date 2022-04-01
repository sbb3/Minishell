/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:25:17 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/31 23:50:21 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cc;

	if (! str)
		return (NULL);
	cc = (char)c;
	while (*str && *str != cc)
		str++;
	if (*str == cc)
		return ((char *)str);
	return (NULL);
}
