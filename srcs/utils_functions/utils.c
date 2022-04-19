/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:13:54 by adouib            #+#    #+#             */
/*   Updated: 2022/04/19 02:09:39 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

int	isprintable(int c)
{
	if (c > 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_free(char **tokens, size_t tkns_len)
{
	size_t	i;

	i = 0;
	while (i < tkns_len)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	skipspaces(char *s, int *pos, int *space, int w)
{
	int	i;
	int	whitespace;

	i = (*pos);
	whitespace = (*space);
	if (w)
	{
		while (iswhitespace(s[i]))
		{
			whitespace++;
			i++;
		}
	}
	else
	{
		while (iswhitespace(s[i]) || s[i] == '<' || s[i] == '>')
		{
			whitespace++;
			i++;
		}
	}
	(*pos) = i;
	(*space) = whitespace;
}
