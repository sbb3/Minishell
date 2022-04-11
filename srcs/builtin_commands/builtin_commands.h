/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:40:29 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/11 06:57:06 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_COMMANDS_H
#define BUILTIN_COMMANDS_H

# include "../source/source_.h"

typedef struct s_builtin_cmd_data
{
	t_env	**env;
	char	**args;
	int		part_counts;
	int		outfd;
	int		ext_stts;
} t_builtin_cmd_data;


void	builtin_cmd__echo_(t_builtin_cmd_data *data);
void	builtin_cmd__env_(t_builtin_cmd_data *data);
void	builtin_cmd__exit_(t_builtin_cmd_data *data);
void	builtin_cmd__pwd_(t_builtin_cmd_data *data);
void	builtin_cmd__unset_(t_builtin_cmd_data *data);
void	builtin_cmd__cd_(t_builtin_cmd_data *data);
void	builtin_cmd__export_(t_builtin_cmd_data *data);
void	dir_checker_in_multi_parts(char *dirname, t_builtin_cmd_data *data);
bool	directory_exist_or_not(char *dirname, t_builtin_cmd_data *data);
bool	builtin_cmd__cd__chdir_and_modify_env(char *dirname, t_env **envs, t_env *pwd, t_env *old_pwd);
void	replace_or_add_env__value_key_(t_env **envs, t_env *env, char *key, char *value);
t_env	*get_env_by_its_key(t_env *env, char *key);



#endif
