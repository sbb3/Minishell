/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:29:53 by adouib            #+#    #+#             */
/*   Updated: 2022/04/07 03:02:02 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	ft_error(int c)
{
	if (c == 1)
		perror("Input file not found!");
	else if (c == 2)
		perror("Output file error!");
	else if (c == 3)
		write(2, "Format : ./pipex file1 cmd1 cmd2 file2\n", 41);
	else if (c == 4)
		perror("Pipe func error!");
	else if (c == 5)
		perror("Fork func error!");
	else if (c == 6)
		perror("cmd1 first dup2 error!");
	else if (c == 7)
		perror("cmd1 second dup2 error!");
	else if (c == 8)
		perror("cmd1 execve error!");
	else if (c == 9)
		perror("cmd2 first dup2 error!");
	else if (c == 10)
		perror("cmd2 second dup2 error!");
	else if (c == 11)
		perror("cmd2 execve error!");
	exit(EXIT_FAILURE);
}

void	ft_error2(int c)
{
	if (c == 12)
		write(2, "permission denied error\n", 24);
	else if (c == 13)
		write(2, "Command not found error\n", 24);
	exit(EXIT_FAILURE);
}

void	quit(char *s, int errornum)
{
	printf("%s\n", s);
	exit(errornum);
}

void	exit_if_null(void *p, char *message)
{
	if (!p)
	{
		printf("%s\n", message);
		exit(EXIT_FAILURE);
	}
}

int	syntax_error(char *s)
{
	printf("%s\n", s);
	return (0);
}
