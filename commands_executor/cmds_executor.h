/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:17:02 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/01 18:01:11 by jchakir          ###   ########.fr       */
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
char    *var_to_value_in_str(char *src, t_env *env, int exit_status);
char	*strdup_from_to__address_(char *start, char *end);
char	*var_to_value_in__str__from_to__address_(char *start, char *end, t_env *env, int exit_status);
bool	quotes_and_forbidden_chars_checker(t_shell *shell);



int ft_get_here_doc(char const *limiter);


#endif
