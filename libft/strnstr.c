/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:16:53 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/20 17:08:11 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ismatch(char *s, char *q)
{
	while (*s && *q && *s == *q)
	{
		s++;
		q++;
	}
	if (! *q)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s;
	char	*q;
	size_t	qlen;

	if (!haystack && !len)
		return (NULL);
	if (! *needle)
		return ((char *)haystack);
	s = (char *)haystack;
	q = (char *)needle;
	qlen = ft_strlen(needle);
	while (*s && qlen <= len--)
	{
		if (*s == *q && ft_ismatch(s, q))
			return (s);
		s++;
	}
	return (NULL);
}
