/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:20:26 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 20:25:16 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static int	ft_set_start(const char *s, const char *set)
{
	int	start;

	start = 0;
	while (ft_inset(*s, set) && *s++)
		start++;
	return (start);
}

static int	ft_set_end(const char *str, const char *set)
{
	int	end;

	end = ft_strlen(str) - 1;
	while (ft_inset(*(str + end), set) && end)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*d;
	char	*save_d;
	int		start;
	int		end;

	if (! s || ! set || ! *s)
		return (ft_calloc(1, 1));
	start = ft_set_start(s, set);
	end = ft_set_end(s, set);
	if (start > end)
		return (ft_calloc(1, 1));
	d = malloc(end - start + 2);
	if (! d)
		return (d);
	save_d = d;
	while (start <= end)
		*d++ = *(s + start++);
	*d = 0;
	return (save_d);
}
