/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__cd_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:09:27 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 23:05:19 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

static t_env	*get_env_by_its_key(t_env *env, char *key)
{
	while (env)
	{
		if (ft_memcmp(env->key, key, ft_strlen(key) + 1) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

static void	replace_or_add_env__value_key_(t_env **envs, t_env *env, char *key, char *value)
{
	
	if (env)
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
	else
		env_add_back_to_envs(envs, new_env(key, value));
}

static bool	builtin_cmd__cd__chdir_and_modify_env(char *dirname, t_env **envs, t_env *pwd, t_env *old_pwd)
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
		if (oldcwd && ft_memcmp(cwd, oldcwd, ft_strlen(oldcwd) + 1))
			replace_or_add_env__value_key_(envs, old_pwd, "OLDPWD", oldcwd);
		return (true);
	}
	else
		perror(dirname);
	return (false);
}

static void	builtin_cmd__cd__dirname_parser(char *dirname, t_env **envs, int outfd)
{
	t_env	*pwd;
	t_env	*old_pwd;
	t_env	*home;

	pwd = get_env_by_its_key(*envs, "PWD");
	old_pwd = get_env_by_its_key(*envs, "OLDPWD");

	if (*dirname == '-' && *(dirname + 1) == '\0')
	{
		if (old_pwd)
		{
			dirname = old_pwd->value;
			if (builtin_cmd__cd__chdir_and_modify_env(dirname, envs, pwd, old_pwd))
			{
				ft_putstr_fd(dirname, outfd);
				write(outfd, "\n", 1);
			}
		}
		else
			put_custom_error("cd: ", "OLDPWD not set");
	}
	else if (*dirname == '~')
	{
		home = get_env_by_its_key(*envs, "HOME");
		if (home)
		{
			dirname = ft_strjoin(home->value, dirname + 1);
			builtin_cmd__cd__chdir_and_modify_env(dirname, envs, pwd, old_pwd);
			free(dirname);
		}
		else
			put_custom_error("cd: ", "HOME not set");
	}
	else if (*dirname == '\0')
		return ;
	else
		builtin_cmd__cd__chdir_and_modify_env(dirname, envs, pwd, old_pwd);
}

void	builtin_cmd__cd_(char **args, t_env **env, int outfd, int parts_count)
{
	DIR		*dir;
	t_env	*old_pwd;

	if (args[0] == NULL)
	{
		if (parts_count == 1)
			builtin_cmd__cd__dirname_parser("~", env, outfd);
	}
	else if (args[1])
		put_custom_error("cd: ", "too many arguments");
	else if (parts_count == 1)
		builtin_cmd__cd__dirname_parser(args[0], env, outfd);
	else
	{
		if (args[0][0] == '\0')
			return ;
		if (args[0][0] == '-' && args[0][1] == '\0')
		{
			old_pwd = get_env_by_its_key(*env, "OLDPWD");
			if (old_pwd)
			{
				ft_putstr_fd(old_pwd->value, outfd);
				write(outfd, "\n", 1);
			}
			return ;
		}
		dir = opendir(args[0]);
		if (dir)
			closedir(dir);
		else
			perror(args[0]);
	}
}
