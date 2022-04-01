/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:55:25 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/31 12:25:02 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cmds_executor.h"

// static char **get_cmd_and_args_crude__khame_(t_cmd_data *cmd_data)
// {
// 	t_component	*component;
// 	char		**cmd_and_args;
// 	int			i;

// 	component = cmd_data->component;
// 	// cmd_and_args = ft_calloc()
// }

void	cmd_executor(t_cmd_data *cmd_data)
{
	int		infd;
	int		outfd;
	int		i;
	int		pipe_fds[2];

	pipe(pipe_fds);
	close(pipe_fds[1]);
	if (set_input_and_output_fds__minner_(&infd, &outfd, cmd_data) == false)
	{
		cmd_data->pid_and_pipefd[1] = pipe_fds[0];
		cmd_data->exit_status = 1;
		return ;
	}
	if (infd != 0)
		cmd_data->infd = infd;
	i = 0;




	if (infd != 0)
		close(infd);
}
