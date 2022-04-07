/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:40:29 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 01:52:25 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_COMMANDS_H
#define BUILTIN_COMMANDS_H

# include "../source/source_.h"

void	builtin_cmd__echo_(char **args, int outfd);
void	builtin_cmd__env_(t_env	*env, char **args, int outfd);
void	builtin_cmd__exit_(char	**args, int part_counts);
void	builtin_cmd__pwd_(char **args, int outfd);
void	builtin_cmd__unset_(t_shell	*shell, char **args);
void	builtin_cmd__cd_(char **args, t_env **env, int outfd, int parts_count);
void	builtin_cmd__export_(char **args, t_env **envs, int outfd, int parts_count);

#endif
