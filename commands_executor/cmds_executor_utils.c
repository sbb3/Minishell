/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:36:01 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/05 23:15:19 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

char	**get_cmd_and_args__from_component_(t_component *component)
{
	int		index;
	char	**cmd_and_args;

	index = list_component_size(component);
	cmd_and_args = (char **)ft_calloc(index + 1, sizeof(char *));
	index = 0;
	while (component)
	{
		if (component->type == ARGS)
		{
			cmd_and_args[index] = component->content;
			index++;
		}
		component = component->next;
	}
	return (cmd_and_args);
}

bool	this_is_builtin_command(t_component *component)
{
	char	*str;
	char	*builtin_cmds[7] = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	// char	*builtin_cmds[7];
	int		index;

	str = NULL;
	while (component)
	{
		if (component->type == ARGS)
		{
			str = component->content;
			break ;
		}
		component = component->next;
	}
	if (str == NULL)
		return (false);
	index = 0;
	while (index < 7)
	{
		if (ft_memcmp(str, builtin_cmds[index], ft_strlen(str) + 1) == 0)
			return (true);
		index++;
	}
	return (false);
}
