/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:44 by adouib            #+#    #+#             */
/*   Updated: 2022/03/31 21:34:47 by adouib           ###   ########.fr       */
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

void	printing(t_shell *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->parts_count)
	{
		j = -1;
		while (data->separator[i])
		{
			printf("%s\n", data->separator[i]->content);
			printf("%d\n", data->separator[i]->type);
			data->separator[i] = data->separator[i]->next;
		}
	}
}

