/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_here_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:13 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/09 23:19:22 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands_executor.h"

static void ft_get_here_doc_with_gunl(char *limiter, int outfd)
{
    char *line;

	while (1)
	{
		line = readline("heredoc> ");
		if (! line)
			break ;
		if (! ft_memcmp(line, limiter, ft_strlen(limiter) + 1))
			break ;
		write(outfd, line, ft_strlen(line));
		write(outfd, "\n", 1);
		free(line);
	}
	free(line);
	exit (0);
}

int ft_get_here_doc(char *limiter)
{
    int fd_pipe[2];
    pid_t pid;

	if (pipe(fd_pipe) < 0)
		return -1;
	pid = fork();
	if (pid < 0)
		return -1;
	if (! pid)
		ft_get_here_doc_with_gunl(limiter, fd_pipe[1]);
	close(fd_pipe[1]);
	waitpid(pid, NULL, 0);
	return (fd_pipe[0]);
}
