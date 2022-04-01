/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:33 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/26 22:07:47 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

# define MALLOC_ERROR "error malloc()"
# define PIPE_ERROR "error pipe()"
# define FORK_ERROR "error fork()"
# define WAITPID_ERROR "error waitpid()"
# define DUP2_ERROR "error dup2()"
# define READ_ERROR "error read()"
# define WRITE_ERROR "error write()"
# define OPEN_ERROR "error open()"
# define READ_OR_WRITE_ERROR "error read()/write()"
# define COMMAND_NOT_FOUND_ERROR "command not found: "






void ft_put_custom_error(char const *s1, char const *s2);
void ft_free_perror_exit(char **ptr2D_1, char **ptr2D_2, char *ptr1D,\
								char const *error_str);
void ft_free_2D_pointer(char *ptr_2D[]);
int ft_fork_child_proc_to_exec_cmd(char const *cmd, char *paths[], int infd);
int ft_get_here_doc(char const *limiter);
void ft_pipex_here_doc(int args_count, char const **args, char **paths);
void ft_pipex_multiple_pipes(int args_count, char const **args, char **paths);
void ft_pipex(int argc, char const **argv, char const **envp);

#endif
