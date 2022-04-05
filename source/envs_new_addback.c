/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_new_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:37:59 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/04 23:38:57 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

t_env	*new_env(char *key, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->key = ft_strdup(key);
	env->value = ft_strdup(value);
	env->next = NULL;
	return (env);
}

void	env_add_back_to_envs(t_env **envs, t_env *new_env)
{
	t_env	*env;

	if (*envs == NULL)
	{
		*envs = new_env;
		return ;
	}
	env = *envs;
	while (env->next)
		env = env->next;
	env->next = new_env;
}
