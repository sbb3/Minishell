/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:15:30 by adouib            #+#    #+#             */
/*   Updated: 2022/03/29 10:18:47 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	pipes_count(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '|')
			count++;
		i++;
	}
	return (count);
}

void	alloc_init(t_shell *data)
{
	data->start = 0;
	data->pids_and_pipefds = NULL;
	data->exit_status = 0;
	data->parts_count = pipes_count(data->prompt_input) + 1;
	data->separator = malloc(sizeof(t_component *) * data->parts_count);
	exit_if_null(data->separator, "Allocation failed");
	set_null(data);
}
