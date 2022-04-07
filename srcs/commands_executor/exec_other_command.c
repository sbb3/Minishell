/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_other_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:44:35 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 01:07:48 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

char *ft_get_cmd_full_path(char *path, char *cmd)
{
	char	*path_slash;
	char	*cmd_full_path;
	char	**paths;

	if (*cmd == '\0')
	{
		put_custom_error("", COMMAND_NOT_FOUND_ERROR);
		exit (EXIT_FAILURE);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_split(path, ':');
    while (*paths)
    {
		path_slash = ft_strjoin(*paths, "/");
        cmd_full_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
        if (access(cmd_full_path, F_OK) == 0)
            return (cmd_full_path);
        free(cmd_full_path);
        paths++;
    }
    put_custom_error(cmd, COMMAND_NOT_FOUND_ERROR);
	exit (1);
}

static void	ft_execut_command(char *cmd_path, char **args,char **envs, int infd, int outfd)
{
	if (dup2(infd, 0) < 0 || dup2(outfd, 1) < 0)
	{
		custom_msg_then_perror(DUP2_ERROR);
		exit (EXIT_FAILURE);
	}
	if (execve(cmd_path, args, envs) < 0)
	{
		custom_msg_then_perror(args[0]);
		exit(1);
	}
}

int get__infd_outfd__and_cmd_full_path_then_exec_it(t_cmd_data *cmd_data, int outfd)
{
	char	*cmd_full_path;
	char	**cmd_and_args;
	int		input_fd;
	int		output_fd;

	if (set_input_and_output_fds__minner_(&input_fd, &output_fd, cmd_data) == false)
		exit (1);
	if (input_fd == 0)
		input_fd = cmd_data->infd;
	if (output_fd == 1)
		output_fd = outfd;
	cmd_and_args = get_cmd_and_args__from_component_(cmd_data->component);
	if (*cmd_and_args == NULL)
		exit (EXIT_FAILURE);

	cmd_full_path = ft_get_cmd_full_path(cmd_data->path_env, cmd_and_args[0]);

	ft_execut_command(cmd_full_path, cmd_and_args, environ, input_fd, output_fd);

	exit(1);
}

// void	exec_other_command(t_cmd_data *cmd_data, int outfd)
// {
	
// 		cmd_data->pid_and_pipefd[0] = fork();
// 		if (cmd_data->pid_and_pipefd[0] == 0)
// 		{
// 			close(pipe_fds[0]);
// 			get__infd_outfd__and_cmd_full_path_then_exec_it(cmd_data,shell->envs, outfd);
// 		}
// }
