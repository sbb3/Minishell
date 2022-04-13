/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__cd_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 03:26:03 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/13 01:53:00 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

t_env	*get_env_by_its_key(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	replace_or_add_env__value_key_(t_env **envs, t_env *env, char *key, char *value)
{
	
	if (env)
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
	else
		env_add_back_to_envs(envs, new_env(key, value));
}

bool	builtin_cmd__cd__chdir_and_modify_env(char *dirname, t_env **envs, t_env *pwd, t_env *old_pwd)
{
	char	buff[251];
	char	oldbuff[251];
	char	*cwd;
	char	*oldcwd;

	oldcwd = getcwd(oldbuff, 251);
	if (chdir(dirname) == 0)
	{
		cwd = getcwd(buff, 251);
		if (cwd)
			replace_or_add_env__value_key_(envs, pwd, "PWD", cwd);
		if (oldcwd && (ft_strcmp(cwd, oldcwd) || old_pwd == NULL))
			replace_or_add_env__value_key_(envs, old_pwd, "OLDPWD", oldcwd);
		return (true);
	}
	else
		custom_msg_then_perror(dirname);
	return (false);
}

bool	directory_exist_or_not(char *dirname, t_builtin_cmd_data *data)
{
	DIR		*dir;

	dir = opendir(dirname);
	if (dir)
		closedir(dir);
	else
	{
		data->ext_stts = 1;
		custom_msg_then_perror(dirname);
		return (false);
	}
	return (true);
}

void	dir_checker_in_multi_parts(char *dirname, t_builtin_cmd_data *data)
{
	t_env	*temp;

	if (*dirname == '\0')
		return ;
	else if (*dirname == '-' && *(dirname + 1) == '\0')
	{
		temp = get_env_by_its_key(*data->env, "OLDPWD");
		if (temp)
		{
			if (directory_exist_or_not(temp->value, data))
				ft_putendl_fd(temp->value, data->outfd);
		}
		else
		{
			data->ext_stts = 1;
			put_custom_error("cd: ", "OLDPWD not set");
		}
	}
	else if (*dirname == '~')
	{
		temp = get_env_by_its_key(*data->env, "HOME");
		if (temp)
		{
			dirname = ft_strjoin(temp->value, dirname + 1);
			directory_exist_or_not(dirname, data);
			free(dirname);
		}
		else
		{
			data->ext_stts = 1;
			put_custom_error("cd: ", "HOME not set");
		}
	}
	else
		directory_exist_or_not(dirname, data);
}
