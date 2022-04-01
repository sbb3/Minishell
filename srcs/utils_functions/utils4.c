/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:31:59 by adouib            #+#    #+#             */
/*   Updated: 2022/03/31 21:34:42 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	count(char *s[])
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcut_from_to(char *s, int from, int to)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (to - from) + 1);
	if (!buf)
		return (0);
	i = 0;
	while (from < to)
	{
		buf[i] = s[from];
		from++;
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	gettoken_helper(char *token, int to, int *lastpos)
{
	if (*token == '\0')
	{
		if (ft_strlen(token) == to)
		{
			*lastpos = to;
			return (0);
		}
		else
		{
			*lastpos = to + 1;
			return (0);
		}
	}
	else
		*lastpos = to;
	return (1);
}

void	gettoken_helper2(char *token, int *end)
{
	int	dquotes_state;
	int	squotes_state;
	int	to;

	dquotes_state = 0;
	squotes_state = 0;
	to = (*end);
	while (token[to])
	{
		if (token[to] == DOUBLEQUOTE)
			quoteshelper(token, &to, DOUBLEQUOTE);
		if (token[to] == SINGLEQUOTE)
			quoteshelper(token, &to, SINGLEQUOTE);
		if (token[to] == ' ')
			break ;
		if (token[to] == '<' || token[to] == '>' || token[to] == '|')
			break ;
		to++;
	}
	(*end) = to;
}

void	skipspaces(char *s, int *pos, int *space)
{
	int	i;
	int	whitespace;

	i = (*pos);
	whitespace = (*space);
	while (iswhitespace(s[i]))
	{
		whitespace++;
		i++;
	}
	*pos = i;
	*space = whitespace;
}
