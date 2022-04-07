/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__env_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:39:44 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 01:52:12 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

void	builtin_cmd__env_(t_env	*env, char **args, int outfd)
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
		{
			ft_putstr_fd(env->key, outfd);
			write(outfd, "=", 1);
			ft_putstr_fd(env->value, outfd);
			write(outfd, "\n", 1);
		}
		env = env->next;
	}
}
