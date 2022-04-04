/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__unset_.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:23:10 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/03 17:03:30 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

static void	free_this_env_node__key_value_node__(t_env *env)
{
	free(env->key);
	free(env->value);
	free(env);
}

static void	delete_this_env_varible(t_shell	*shell, char *key)
{
	t_env	*env;
	t_env	*last_env;

	if (shell->envp == NULL)
		return ;
	env = shell->envp;
	if (ft_memcmp(env->key, key, ft_strlen(key) + 1) == 0)
	{
		shell->envp = env->next;
		free_this_env_node__key_value_node__(env);
		return ;
	}
	last_env = env;
	env = env->next;
	while (env)
	{
		if (ft_memcmp(env->key, key, ft_strlen(key) + 1) == 0)
		{
			last_env->next = env->next;
			free_this_env_node__key_value_node__(env);
			return ;
		}
		last_env = env;
		env = env->next;
	}
}

void	builtin_cmd__unset_(t_shell	*shell, char **args)
{
	int		index;

	if (args[0] == NULL)
	{
		put_custom_error("unset: ", "not enough arguments");
		return ;
	}
	if (shell->parts_count != 1)
		return ;
	index = 0;
	while (args[index])
	{
		delete_this_env_varible(shell, args[index]);
		index++;
	}
}
