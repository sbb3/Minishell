/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:05:35 by adouib            #+#    #+#             */
/*   Updated: 2022/04/01 21:54:10 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../incl/minishell.h"

int	more_check(t_shell *data)
{
	int	i;

	i = -1;
	while (++i < data->tokens_len)
	{
		if (!ft_strcmp(data->tokens[i], "<") && data->tokens[++i] == NULL)
		{
			return 0;
		}
	}
	return 1;
}
