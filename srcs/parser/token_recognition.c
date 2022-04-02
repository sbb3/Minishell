/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:29:19 by adouib            #+#    #+#             */
/*   Updated: 2022/04/02 15:21:07 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

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
