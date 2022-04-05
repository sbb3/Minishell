/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:55:25 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/05 23:12:39 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

void	cmd_executor__fork_child_proc_(t_cmd_data *cmd_data, t_shell *shell)
{
	int	pipe_fds[2];
	int	outfd;

	pipe(pipe_fds);
	cmd_data->pid_and_pipefd[1] = pipe_fds[0];

	if (cmd_data->cmd_id < shell->parts_count - 1)
		outfd = pipe_fds[1];
	else
		outfd = 1;

	if (this_is_builtin_command(cmd_data->component))
		exec_builtin_command(cmd_data, shell, outfd);
	else
		printf("other function\n");
	// {
	// 	cmd_data->pid_and_pipefd[0] = fork();
	// 	if (cmd_data->pid_and_pipefd[0] == 0)
	// 	{
	// 		close(pipe_fds[0]);
	// 		get__infd_outfd__and_cmd_full_path_then_exec_it(cmd_data,shell->envs, outfd);
	// 	}
	// }
	
	close(pipe_fds[1]);
}
