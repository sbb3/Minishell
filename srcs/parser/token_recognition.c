/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:29:19 by adouib            #+#    #+#             */
/*   Updated: 2022/04/03 18:20:55 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	phaseone_helper(t_shell *data, int *k, int type1, int type2)
{
	int	i;

	i = (*k);
	if (type1 || type2)
	{
		data->tkns_recognition[i] = type1;
		data->tkns_recognition[++i] = type2;
		(*k) = i;
	}
	else
		data->tkns_recognition[i] = COMMAND;
}

void	phasezero(t_shell *data)
{
	int	i;

	i = -1;
	while (++i < data->tokens_len)
		data->tkns_recognition[i] = ARGS;
}

void	phaseone(t_shell *data)
{
	int	k;
	int	i;

	k = 0;
	i = -1;
	while (++i < data->tokens_len)
	{
		if (!ft_strcmp(data->tokens[i], "<"))
			phaseone_helper(data, &i, LESS, INFILE);
		else if (!ft_strcmp(data->tokens[i], ">"))
			phaseone_helper(data, &i, GREATER, OUTFILE);
		else if (!ft_strcmp(data->tokens[i], "<<"))
			phaseone_helper(data, &i, HEREDOC, DELIMITER);
		else if (!ft_strcmp(data->tokens[i], ">>"))
			phaseone_helper(data, &i, APPEND, OUTFILE_APPEND);
		else
		{
			if (!k)
			{
				phaseone_helper(data, &i, 0, 0);
				k = 1;
			}
		}
	}
}
