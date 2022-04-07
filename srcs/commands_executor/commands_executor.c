/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:44:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 21:15:47 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

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

static void	wait_all_pids_then_close_pipefds(t_shell *shell, int *pids)
{
	int	index;

	index = 0;
	while (index < shell->parts_count)
	{
		if (pids[index] > 0)
			waitpid(pids[index], &shell->exit_status, 0);
		pids[index] = 0;
		index++;
	}
	// printf(" return status : %d\n", shell->exit_status);
}

void	commands_executor(t_shell *shell)
{
	t_cmd_data	*cmd_data;
	int			index;
	int			*pids;

	free(shell->pids);
	free(shell->pipefds);
	cmd_data = ft_calloc(1, sizeof(t_cmd_data));
	pids = ft_calloc(shell->parts_count, sizeof(int));
	cmd_data->infd = 0;
	cmd_data->path_env = get_path_env_from_envp(shell->envp);
	cmd_data->pids = pids;
	index = 0;
	while (index < shell->parts_count)
	{
		cmd_data->component = shell->separator[index];
		cmd_executor__fork_child_proc_(cmd_data, shell, index);
		cmd_data->infd = cmd_data->pipefd;
		index++;
	}
	wait_all_pids_then_close_pipefds(shell, pids);
	if (cmd_data->pipefd > 2)
		close(cmd_data->pipefd);
	shell->pids = pids;
	free(cmd_data);
}
