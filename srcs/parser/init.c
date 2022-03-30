/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:32:20 by adouib            #+#    #+#             */
/*   Updated: 2022/03/29 16:44:36 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	*token_recognition(t_shell *data)
{
	data->tkns_recognition = malloc(sizeof(int) * data->tokens_len);
	exit_if_null(data->tkns_recognition, "Allocation failed");
	phasezero(data);
	phaseone(data);
	phasetwo(data);
	return (data->tkns_recognition);
}

char	**tokenizer(char *s, int *start)
{
	char	**tokens;
	char	*token;
	int		i;
	int		current_size;

	current_size = INITIAL;
	tokens = malloc(sizeof(*tokens) * INITIAL);
	exit_if_null(tokens, "Allocation failed\n");
	token = get_token(s, start);
	i = 0;
	while (token)
	{
		if (i == current_size)
		{
			current_size *= 2;
			tokens = realloc(tokens, sizeof(*tokens) * current_size);
			exit_if_null(tokens, "Reallocation failed\n");
		}
		tokens[i] = ft_strdup(token);
		free(token);
		token = get_token(s, start);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

void	parser(t_shell *data)
{
	t_component	*newnode;
	int			i;
	int			j;

	alloc_init(data);
	i = -1;
	while (++i < data->parts_count)
	{
		data->tokens = tokenizer(data->prompt_input, &(data->start));
		data->tokens_len = tokens_count(data->tokens);
		data->tkns_recognition = token_recognition(data);
		j = -1;
		while (++j < data->tokens_len)
		{
			if (skip_redirection(data->tkns_recognition[j]))
				continue ;
			else
			{
				newnode = ft_lstnew(data->tokens[j], data->tkns_recognition[j]);
				ft_lstadd_back(&(data->separator)[i], newnode);
			}
		}
		reset_memory(data);
	}
	free(data->prompt_input);
}
