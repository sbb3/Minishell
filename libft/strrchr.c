/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:19:15 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 21:24:37 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	char	cc;
	int		len;

	cc = (char)c;
	s = (char *)str;
	len = ft_strlen(str);
	if (! cc)
		return (s + len);
	while (len--)
		if (s[len] == cc)
			return (s + len);
	return (NULL);
}
