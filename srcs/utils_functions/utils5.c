/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:44 by adouib            #+#    #+#             */
/*   Updated: 2022/04/03 18:29:34 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

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
	(*pos) = i;
	(*space) = whitespace;
}

void	skipspaces2(char *s, int *pos, int *space)
{
	int	i;
	int	whitespace;

	i = (*pos);
	whitespace = (*space);
	while (iswhitespace(s[i]) || s[i] == '<' || s[i] == '>')
	{
		whitespace++;
		i++;
	}
	(*pos) = i;
	(*space) = whitespace;
}

void	printing(t_shell *data)
{
	t_component	*current_part;
	int			i;

	i = -1;
	while (++i < data->parts_count)
	{
		current_part = data->separator[i];
		while (current_part)
		{
			printf("%s\n", current_part->content);
			printf("%d\n", current_part->type);
			current_part = current_part->next;
		}
	}
}
