/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:17:02 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/02 13:08:56 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_EXECUTOR_H
# define CMD_EXECUTOR_H

# include "../libft/libft.h"
# include "../source/source.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>



typedef struct s_cmd_data
{
	t_component *component;
	char		*path_env;
	int			*pid_and_pipefd;
	int			infd;
	int			cmd_id;
} t_cmd_data;



bool	set_input_and_output_fds__minner_(int *infd, int *outfd, t_cmd_data *cmd_data);
void	commands_executor(t_shell *shell);
void	cmd_executor__fork_child_proc_(t_cmd_data *cmd_data, t_shell *shell);



int ft_get_here_doc(char *limiter);


#endif
