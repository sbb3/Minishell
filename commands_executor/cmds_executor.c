/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:55:25 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/01 00:00:49 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmds_executor.h"

static char *ft_get_cmd_full_path(char *path, char const *cmd)
{
	char 	*path_slash;
    char 	*cmd_full_path;
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
	exit (EXIT_FAILURE);
}

static char	**get_cmd_and_args__from_component_(t_component *component)
{
	int		index;
	char	**cmd_and_args;

	index = ft_lstsize(component);
	cmd_and_args = (char **)ft_calloc(index + 1, sizeof(char *));
	index = 0;
	while (component)
	{
		if (component->type != INFILE && component->type != DELIMITER && \
				component->type != OUTFILE && component->type != OUTFILE_APPEND)
		{
			cmd_and_args[index] = component->content;
			index++;
		}
		component = component->next;
	}
	return (cmd_and_args);
}

static void	ft_execut_command(char *cmd_path, char **args,char **envp, int infd, int outfd)
{
	if (dup2(infd, 0) < 0 || dup2(outfd, 1) < 0)
	{
		custom_msg_then_perror(DUP2_ERROR);
		exit (EXIT_FAILURE);
	}
	if (! cmd_path)
		exit (EXIT_FAILURE);
	if (execve(cmd_path, args, envp) < 0)
	{
		custom_msg_then_perror(args[0]);
		exit(EXIT_FAILURE);
	}
}

int get__infd_outfd__and_cmd_full_path_then_exec_it(t_cmd_data *cmd_data, char **envp, int outfd)
{
	char	*cmd_full_path;
	char	**cmd_and_args;
	int		input_fd;
	int		output_fd;

	if (set_input_and_output_fds__minner_(&input_fd, &output_fd, cmd_data) == false)
		exit (EXIT_FAILURE);
	cmd_and_args = get_cmd_and_args__from_component_(cmd_data->component);
	if (*cmd_and_args == NULL)
		exit (EXIT_FAILURE);
	if (input_fd == 0)
		input_fd = cmd_data->infd;
	if (output_fd == 1)
		output_fd = outfd;

	cmd_full_path = ft_get_cmd_full_path(cmd_data->path_env, cmd_and_args[0]);

	ft_execut_command(cmd_full_path, cmd_and_args, envp, input_fd, output_fd);

	exit(EXIT_FAILURE);
}

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

	cmd_data->pid_and_pipefd[0] = fork();
	if (cmd_data->pid_and_pipefd[0] == 0)
	{
		close(pipe_fds[0]);
		get__infd_outfd__and_cmd_full_path_then_exec_it(cmd_data, outfd);
	}

	close(pipe_fds[1]);
}
