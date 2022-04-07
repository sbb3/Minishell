/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:13:54 by adouib            #+#    #+#             */
/*   Updated: 2022/04/07 00:49:15 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

// int	ft_isalnum(int c)
// {
// 	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') \
// 		|| (c >= '0' && c <= '9'))
// 		return (1);
// 	return (0);
// }

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*buf;
// 	size_t	string_size;
// 	size_t	i;

// 	string_size = ft_strlen(s);
// 	buf = (char *) malloc(sizeof(char) * string_size + 1);
// 	if (!buf)
// 		return ((void *)0);
// 	i = 0;
// 	while (s[i])
// 	{
// 		buf[i] = s[i];
// 		i++;
// 	}
// 	buf[i] = '\0';
// 	return (buf);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((s1[i] - s2[i]));
}

// char	*ft_strchr(char *s, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char) c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }
