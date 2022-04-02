/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:44:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/02 16:50:35 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmds_executor.h"

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

void	commands_executor(t_shell *shell)
{
	t_cmd_data	*cmd_data;
	int			index;
	int			*pids_and_pipefds;
	int			exit_status[1];



	cmd_data = ft_calloc(1, sizeof(t_cmd_data));
	pids_and_pipefds = ft_calloc(shell->parts_count * 2, sizeof(int));
	exit_status[0] = 0;
	cmd_data->infd = 0;
	cmd_data->path_env = get_path_env_from_envp(shell->envp);

	index = 0;
	while (index < shell->parts_count)
	{	
		cmd_data->component = shell->separator[index];
		cmd_data->pid_and_pipefd = pids_and_pipefds + index;
		cmd_data->cmd_id = index;
		cmd_executor__fork_child_proc_(cmd_data, shell);
		cmd_data->infd = cmd_data->pid_and_pipefd[index + 1];
		index++;
	}

	index = 0;
	while (index < shell->parts_count * 2)
	{
		if (pids_and_pipefds[index] > 0)
			waitpid(pids_and_pipefds[index], exit_status, 0);
		pids_and_pipefds[index] = 0;
		index = index + 2;
	}

	index = 0;
	while (index < shell->parts_count * 2)
	{

		// printf("fd is: %d\n", pids_and_pipefds[index + 1]);
		
		if (pids_and_pipefds[index + 1] > 2)
			close(pids_and_pipefds[index + 1]);
		pids_and_pipefds[index + 1] = 0;
		index = index + 2;
	}

	free(pids_and_pipefds);
	shell->exit_status = exit_status[0];
	free(cmd_data);
}
