/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:40:29 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/17 02:48:32 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_COMMANDS_H
# define BUILTIN_COMMANDS_H

# include "../source/source_.h"

typedef struct s_builtin_cmd_data
{
	t_env	**env;
	char	**args;
	int		part_counts;
	int		outfd;
	int		ext_stts;
}	t_builtin_cmd_data;

void	put_not_a_valid_identifier_error(char *cmdname, char *str);
bool	is_this_key_valid_as_var_key(char *str);
void	builtin_cmd__echo_(t_builtin_cmd_data *data);
void	builtin_cmd__env_(t_builtin_cmd_data *data);
void	builtin_cmd__exit_(t_builtin_cmd_data *data);
void	builtin_cmd__pwd_(t_builtin_cmd_data *data);
void	builtin_cmd__unset_(t_builtin_cmd_data *data);
void	builtin_cmd__cd_(t_builtin_cmd_data *data);
void	builtin_cmd__export_(t_builtin_cmd_data *data);
void	dir_checker_in_multi_parts(char *dirname, t_builtin_cmd_data *data);
bool	directory_exist_or_not(char *dirname, t_builtin_cmd_data *data);
bool	_cd__chdir_and_modify_env(char *dirname, t_env **envs, t_env *pwd, t_env *old_pwd);

#endif
