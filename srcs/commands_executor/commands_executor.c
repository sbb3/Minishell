/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:44:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/17 01:48:43 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands_executor.h"

static char	*get_path_env_from_envp(t_env *envp)
{
	while (envp)
	{
		if (ft_memcmp(envp->key, "PATH", 5) == 0)
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}

static void	wait_all_pids(t_shell *shell, int *pids, int builtin_ext_stts)
{
	int	index;
	int	exit_status;

	index = 0;
	while (index < shell->parts_count)
	{
		if (pids[index] > 0)
		{
			waitpid(pids[index], &exit_status, 0);
			if (WIFSIGNALED(exit_status))
				shell->exit_status = 130;
			else
				shell->exit_status = WEXITSTATUS(exit_status);
		}
		else
			shell->exit_status = builtin_ext_stts;
		pids[index] = 0;
		index++;
	}
}

void	commands_executor(t_shell *shell)
{
	t_cmd_data	*cmd_data;
	int			index;
	int			*pids;

	cmd_data = ft_calloc(1, sizeof(t_cmd_data));
	pids = ft_calloc(shell->parts_count, sizeof(int));
	cmd_data->infd = 0;
	cmd_data->path_env = get_path_env_from_envp(shell->envp);
	cmd_data->pids = pids;
	cmd_data->envs = shell->envs;
	index = 0;
	while (index < shell->parts_count)
	{
		cmd_data->component = shell->separator[index];
		cmd_executor__fork_child_proc_(cmd_data, shell, index);
		cmd_data->infd = cmd_data->pipefd;
		index++;
	}
	wait_all_pids(shell, pids, cmd_data->builtin_ext_stts);
	if (cmd_data->pipefd > 2)
		close(cmd_data->pipefd);
	free(pids);
	free(cmd_data);
}
