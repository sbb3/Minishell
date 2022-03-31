/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:02:47 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 21:16:53 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*s;
	char	cc;

	cc = (char)c;
	s = (char *)str;
	if (! n)
		return (NULL);
	while (*s != cc && --n)
		s++;
	if (*s == cc)
		return (s);
	return (NULL);
}
