/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__export_.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:46:08 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/15 00:56:01 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

static void	replace_or_add_env__value_key_for_export(t_env **envs, \
								char *key, char *value, int part_counts)
{
	t_env	*env;

	if (part_counts != 1)
		return ;
	if (*key == '\0')
	{
		env_add_back_to_envs(envs, new_env("", value));
		return ;
	}
	env = get_env_by_its_key(*envs, key);
	if (env)
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
	else
		env_add_back_to_envs(envs, new_env(key, value));
}

static void	builtin_cmd__export__print_all_envs(t_env *env, int outfd)
{
	while (env)
	{
		write(outfd, "declare -x ", 11);
		if (*env->key == '\0')
			ft_putstr_fd(env->value, outfd);
		else
		{
			ft_putstr_fd(env->key, outfd);
			write(outfd, "=\"", 2);
			ft_putstr_fd(env->value, outfd);
			write(outfd, "\"", 1);
		}
		write(outfd, "\n", 1);
		env = env->next;
	}
}

static void	__export__add_empty_key(char *arg, t_builtin_cmd_data *data)
{
	if (is_this_key_valid_as_var_key(arg))
		replace_or_add_env__value_key_for_export(data->env, "", \
											arg, data->part_counts);
	else
	{
		data->ext_stts = 1;
		put_not_a_valid_identifier_error("export", arg);
	}
}

static void	__export__add_new_env(char *arg, char *equal_index, \
									t_builtin_cmd_data *data)
{
	char	*key;

	key = strdup_from_to__address_(arg, equal_index);
	if (is_this_key_valid_as_var_key(key))
		replace_or_add_env__value_key_for_export(data->env, key, \
										equal_index + 1, data->part_counts);
	else
	{
		data->ext_stts = 1;
		put_not_a_valid_identifier_error("export", arg);
	}
	free(key);
}

void	builtin_cmd__export_(t_builtin_cmd_data *data)
{
	char	*equal_index;
	char	**args;

	data->ext_stts = 0;
	args = data->args;
	if (args[0] == NULL)
		builtin_cmd__export__print_all_envs(*data->env, data->outfd);
	while (*args)
	{
		equal_index = ft_strchr(*args, '=');
		if (equal_index == NULL)
			__export__add_empty_key(*args, data);
		else
			__export__add_new_env(*args, equal_index, data);
		args++;
	}
}
