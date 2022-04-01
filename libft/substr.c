/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:25:31 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 21:38:00 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	char	*save_r;
	size_t	l;

	if (! s)
		return (0);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (l - start < len)
		len = l - start;
	r = malloc((len + 1) * sizeof(char));
	if (! r)
		return (NULL);
	save_r = r;
	while (len--)
		*r++ = s[start++];
	*r = 0;
	return (save_r);
}
