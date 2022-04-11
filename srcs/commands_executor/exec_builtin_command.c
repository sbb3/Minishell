/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:44:06 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/11 07:34:20 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

static t_builtin_cmd_data	*set_init_data_struct(t_shell *shell, int outfd)
{
	t_builtin_cmd_data	*data;

	data = ft_calloc(1, sizeof(t_builtin_cmd_data));
	check_if_null__malloc__exit_(data, MALLOC_ERROR);
	data->env = &shell->envp;
	data->outfd = outfd;
	data->part_counts = shell->parts_count;
	return (data);
}

static void	builtin_commands_executor(char *cmd, t_builtin_cmd_data *data)
{
	if (ft_strcmp(cmd, "echo") == 0)
		builtin_cmd__echo_(data);
	else if (ft_strcmp(cmd, "cd") == 0)
		builtin_cmd__cd_(data);
	else if (ft_strcmp(cmd, "pwd") == 0)
		builtin_cmd__pwd_(data);
	else if (ft_strcmp(cmd, "export") == 0)
		builtin_cmd__export_(data);
	else if (ft_strcmp(cmd, "unset") == 0)
		builtin_cmd__unset_(data);
	else if (ft_strcmp(cmd, "env") == 0)
		builtin_cmd__env_(data);
	else if (ft_strcmp(cmd, "exit") == 0)
		builtin_cmd__exit_(data);
}

static void	free_unneeded_data_and_close_fds(void *data, void *args, int fd1, int fd2)
{
	free(args);
	free(data);
	if (fd1 > 2)
		close(fd1);
	if (fd2 > 2)
		close(fd2);
}

void	exec_builtin_command(t_cmd_data *cmd_data, t_shell *shell, int outfd)
{
	char				**cmd_and_args;
	int					input_fd;
	int					output_fd;
	t_builtin_cmd_data	*data;

	cmd_data->builtin_ext_stts = 0;
	if (set_input_and_output_fds__minner_(&input_fd, &output_fd, cmd_data) == false)
	{
		cmd_data->builtin_ext_stts = 1;
		return ;
	}
	if (output_fd > 2)
		outfd = output_fd;
	cmd_and_args = get_cmd_and_args__from_component_(cmd_data->component);
	if (cmd_and_args[0] == NULL)
		return ;
	data = set_init_data_struct(shell, outfd);
	data->args = cmd_and_args + 1;
	builtin_commands_executor(cmd_and_args[0], data);
	cmd_data->builtin_ext_stts = data->ext_stts;
	free_unneeded_data_and_close_fds(data, cmd_and_args, input_fd, output_fd);
}
