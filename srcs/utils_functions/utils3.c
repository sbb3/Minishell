/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:27:57 by adouib            #+#    #+#             */
/*   Updated: 2022/04/02 15:58:12 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

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
