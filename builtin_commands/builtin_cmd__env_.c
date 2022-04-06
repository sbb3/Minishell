/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__env_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:39:44 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/03 18:08:08 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

void	builtin_cmd__env_(t_env	*env, char **args)
{
	if (args[0])
	{
		put_custom_error("env: ", "too many arguments");
		return ;
	}
	if (env == NULL)
		return ;
	while (env)
	{
		if (*env->key != '\0')
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
