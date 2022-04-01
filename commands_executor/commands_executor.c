/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:44:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/30 22:53:33 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmds_executor.h"

void	free_all__final_content__in_all_components(t_shell *shell)
{
	int	index;
	t_component *component;

	index = 0;
	while (index < shell->parts_count)
	{
		component = shell->separator[index];
		while (component)
		{
			free(component->final_content);
			component = component->next;
		}
		index++;
	}
}

static char	*get_path_env_from_env(t_env *env)
{
	while (env)
	{
		if (ft_memcmp(env->key, "PATH", 5) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	commands_executor(t_shell *shell)
{
	t_cmd_data	*cmd_data;
	int			index;
	int			*pids_and_pipefds;
	int			*other_fds;
	int			exit_status[1];

	if (quotes_and_forbidden_chars_checker(shell) == false)
	{
		put_custom_error(NULL, QUOTES_OR_FORB_CHAR_ERROR);
		return ;
	}

	strings_parser_and_vars_handler(shell);

	pids_and_pipefds = ft_calloc(shell->parts_count * 2, sizeof(int));
	other_fds = ft_calloc(shell->parts_count * 2, sizeof(int));

	index = 0;
	cmd_data->infd = 0;
	cmd_data->env = shell->envp;
	cmd_data->path_env = get_path_env_from_env(shell->envp);

	while (index < shell->parts_count)
	{
		cmd_data->component = shell->separator[index];
		cmd_data->pid_and_pipefd = pids_and_pipefds + index;
		cmd_data->other_fds = other_fds + index;
		cmd_data->cmd_id = index;
		cmd_executor(cmd_data);
		cmd_data->infd = cmd_data->pid_and_pipefd[index + 1];
		index++;
	}

	index = 0;
	while (index < shell->parts_count * 2)
	{
		waitpid(pids_and_pipefds[index], exit_status, 0);
		index = index + 2;
	}

	index = 0;
	while (index < shell->parts_count * 2)
	{
		if (pids_and_pipefds[index + 1] > 2)
			close(pids_and_pipefds[index + 1]);
		index = index + 2;
	}

	index = 0
	while (index < shell->parts_count * 2)
	{
		if (other_fds[index] > 2)
			close(other_fds[index]);
		index++;
	}

	free_all__final_content__in_all_components(shell);
	free(pids_and_pipefds);
	shell->exit_status = exit_status[0];
}
