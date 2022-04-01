/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:09:42 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 20:11:54 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = ft_strlen(src);
	if (! dstsize)
		return (l);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = 0;
	return (l);
}
