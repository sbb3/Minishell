/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:44:06 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/05 23:06:18 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

void	exec_builtin_command(t_cmd_data *cmd_data, t_shell *shell, int outfd)
{
	char	**cmd_and_args;

	cmd_and_args = get_cmd_and_args__from_component_(cmd_data->component);
	if (ft_memcmp(cmd_and_args[0], "echo", 5) == 0)
		builtin_cmd__echo_(cmd_and_args + 1, outfd);
	else if (ft_memcmp(cmd_and_args[0], "cd", 3) == 0)
		builtin_cmd__cd_(cmd_and_args + 1, &shell->envp, outfd, shell->parts_count);
	else if (ft_memcmp(cmd_and_args[0], "pwd", 4) == 0)
		builtin_cmd__pwd_(cmd_and_args + 1, outfd);
	else if (ft_memcmp(cmd_and_args[0], "export", 7) == 0)
		builtin_cmd__export_(cmd_and_args + 1, &shell->envp, outfd, shell->parts_count);
	else if (ft_memcmp(cmd_and_args[0], "unset", 6) == 0)
		builtin_cmd__unset_(shell, cmd_and_args + 1);
	else if (ft_memcmp(cmd_and_args[0], "env", 4) == 0)
		builtin_cmd__env_(shell->envp, cmd_and_args + 1);
	else if (ft_memcmp(cmd_and_args[0], "exit", 5) == 0)
		builtin_cmd__exit_(cmd_and_args + 1);
	free(cmd_and_args);
}
