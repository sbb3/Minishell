/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:44 by adouib            #+#    #+#             */
/*   Updated: 2022/04/01 23:48:56 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

char	**test(char **tokens, size_t size, size_t tkns_len)
{
	char	**new;
	size_t	y;

	new = malloc(sizeof(char *) * size);
	exit_if_null(new, "Allocation failed");
	y = 0;
	while (y < tkns_len)
	{
		new[y] = ft_strdup(tokens[y]);
		y++;
	}
	ft_free(tokens, tkns_len);
	return (new);
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

int	ft_isprint(int c)
{
	if (c > 32 && c <= 126)
		return (1);
	return (0);
}

int	another_helper(int *count, int whitespace)
{
	if (*count > 2 || whitespace != 0)
		return (0);
	(*count)++;
	return (1);
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

