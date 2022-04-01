/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:07:38 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/20 17:05:49 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;
	size_t	ldst;
	size_t	i;

	lsrc = ft_strlen(src);
	if (! dstsize)
		return (lsrc);
	ldst = ft_strlen(dst);
	i = ldst;
	while (*src && i < dstsize - 1)
		dst[i++] = *src++;
	if (i < dstsize)
		dst[i] = 0;
	if (dstsize < ldst)
		return (lsrc + dstsize);
	return (lsrc + ldst);
}
