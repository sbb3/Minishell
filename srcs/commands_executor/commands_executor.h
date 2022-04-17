/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_executor.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:17:02 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/17 02:01:15 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_EXECUTOR_H
# define COMMANDS_EXECUTOR_H

# include "../source/source_.h"
# include "../builtin_commands/builtin_commands.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_cmd_data
{
	t_component	*component;
	char		**envs;
	char		*path_env;
	int			*pids;
	int			pipefd;
	int			infd;
	int			builtin_ext_stts;
}	t_cmd_data;

bool	set_input_and_output_fds__minner_(int *infd, int *outfd, \
											t_cmd_data *cmd_data);
void	commands_executor(t_shell *shell);
void	cmd_executor__fork_child_proc_(t_cmd_data *cmd_data, \
										t_shell *shell, int id);
char	*ft_get_cmd_full_path(char *path, char *cmd);
char	**get_cmd_and_args__from_component_(t_component *component);
bool	this_is_builtin_command(t_component *component);
void	exec_builtin_command(t_cmd_data *cmd_data, t_shell *shell, \
												int outfd);
void		get__infd_outfd__and_cmd_full_path_then_exec_it(\
										t_cmd_data *cmd_data, int outfd);
int		ft_get_here_doc(char *limiter);
void	envs_updater(char *cmd, t_shell *shell);
void	update_envs__only_changed_varibles__(t_shell *shell);
void	update_envs__all_from_scratch__(t_shell *shell, int len_envp);

#endif
