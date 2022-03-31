/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:17:02 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/31 15:07:18 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_EXECUTOR_H
# define CMD_EXECUTOR_H

# include "../libft/libft.h"
# include "../pipex/pipex.h"
# include "../source.h"

# define FORBIDDEN_CHARS "\\;&|><"
# define SHELL_NAME "minishell"
# define QUOTES_OR_FORB_CHAR_ERROR "minishell: unclosed quote or invalid identifier"
# define PIPE_ERROR "pipe() error"

enum e_str_types
{
	SINGLE_Q,
	DOUBLE_Q,
	SIMPLE_STR,
};

typedef struct s_cmd_data
{
	t_component *component;
	t_env		*env;
	char		*path_env;
	int			*pid_and_pipefd;
	int			*other_fds;
	int			exit_status;
	int			infd;
	int			cmd_id;
	int			num_of_parts;
} t_cmd_data;


bool	set_input_and_output_fds__minner_(int *infd, int *outfd, t_cmd_data *cmd_data);
void	commands_executor(t_shell *shell);
char    *var_to_value_in_str(char *src, t_env *env, int exit_status);
char	*strdup_from_to__address_(char *start, char *end);
char	*var_to_value_in__str__from_to__address_(char *start, char *end, t_env *env, int exit_status);
bool	quotes_and_forbidden_chars_checker(t_shell *shell);
void 	put_custom_error(char const *str_error1, char const *str_error2);



#endif
