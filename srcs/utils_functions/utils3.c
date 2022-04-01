/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:27:57 by adouib            #+#    #+#             */
/*   Updated: 2022/04/01 21:52:45 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	localhelper(int *state)
{
	if (!(*state))
		(*state) = 1;
	else
		(*state) = 0;
}

void	localhelper2(int *dqstate, int sqstate)
{
	if (!(*dqstate) && !sqstate)
		(*dqstate) = 1;
	else
		(*dqstate) = 0;
}

void	localhelper3(int *sqstate, int dqstate)
{
	if (!(*sqstate) && !dqstate)
		(*sqstate) = 1;
	else
		(*sqstate) = 0;
}

void	phasetwo_helper(t_shell *data, int i)
{
	int	dq_state;
	int	sq_state;
	int	j;

	dq_state = 0;
	sq_state = 0;
	j = -1;
	while (data->tokens[i][++j])
	{
		if (data->tokens[i][j] == '\"' && !sq_state)
			localhelper(&dq_state);
		else if (data->tokens[i][j] == '\'')
			localhelper(&sq_state);
		else if (data->tokens[i][j] == '$' && sq_state)
		{
			data->tkns_recognition[i] = SQ_USD;
			break ;
		}
		else if ((data->tokens[i][j] == '$' && dq_state) || \
			(data->tokens[i][j] == '$' && !sq_state))
			data->tkns_recognition[i] = USD;
	}
}

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
