/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child_proc_to_exec_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:06 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/28 20:39:45 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *ft_get_cmd_full_path(char *paths[], char const *cmd)
{
	char 	*path_slash;
    char 	*cmd_full_path;

	if (! cmd)
	{
		ft_put_custom_error(COMMAND_NOT_FOUND_ERROR, "");
		return (NULL);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
    while (paths && *paths)
    {
		path_slash = ft_strjoin(*paths, "/");
        cmd_full_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (! cmd_full_path)
			ft_free_perror_exit(paths, NULL, NULL, MALLOC_ERROR);
        if (access(cmd_full_path, F_OK) == 0)
            return (cmd_full_path);
        free(cmd_full_path);
        paths++;
    }
    ft_put_custom_error(COMMAND_NOT_FOUND_ERROR, cmd);
	return (NULL);
}

static void	ft_exec_cmd(char const *cmd_path, char *args[], int infd, int outfd)
{
	char 	*envp[1];

	envp[0] = NULL;
	if (dup2(infd, 0) < 0 || dup2(outfd, 1) < 0)
	{
		perror(DUP2_ERROR);
		exit (EXIT_FAILURE);
	}
	if (! cmd_path)
		exit (EXIT_FAILURE);
	if (execve(cmd_path, args, envp) < 0)
	{
		perror(args[0]);
		exit (EXIT_FAILURE);
	}
}

int ft_fork_child_proc_to_exec_cmd(char const **cmd_and_args, char *paths[], int infd)
{
	char	*cmd_full_path;
	pid_t 	pid;
	int 	fd_pipe[2];

	if (pipe(fd_pipe) < 0)
		return (-1);
	cmd_full_path = ft_get_cmd_full_path(paths, cmd_and_args[0]);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (! pid)
		ft_exec_cmd(cmd_full_path, cmd_and_args, infd, fd_pipe[1]);
	close(fd_pipe[1]);
	close(infd);
	free(cmd_full_path);
	return (fd_pipe[0]);
}
