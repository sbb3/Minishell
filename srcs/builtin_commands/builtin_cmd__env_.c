/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__env_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:39:44 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/11 01:20:25 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

void	builtin_cmd__env_(t_builtin_cmd_data *data)
{
	t_env	*env;

	env = *data->env;
	if (data->args[0])
	{
		put_custom_error("env: ", "too many arguments");
		data->ext_stts = 1;
		return ;
	}
	while (env)
	{
		if (*env->key != '\0')
		{
			ft_putstr_fd(env->key, data->outfd);
			write(data->outfd, "=", 1);
			ft_putstr_fd(env->value, data->outfd);
			write(data->outfd, "\n", 1);
		}
		env = env->next;
	}
	data->ext_stts = 0;
}
