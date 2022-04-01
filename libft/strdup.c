/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:26:10 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 19:28:20 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*r;
	char	*save_r;
	size_t	l;

	l = ft_strlen(string);
	r = (char *)malloc(l + 1);
	if (! r)
		return (NULL);
	save_r = r;
	while (*string)
		*r++ = *string++;
	*r = 0;
	return (save_r);
}
