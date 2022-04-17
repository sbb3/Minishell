/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_hundler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:11:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/17 01:51:40 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/source.h"

static int	set_or_get_last_ctrl_c(int setter, int new_value)
{
	static int	is_last_ctrl_c;

	if (setter)
		is_last_ctrl_c = new_value;
	return (is_last_ctrl_c);
}

void	sig_hundler__ctrl_c__before_readline(int sig)
{
	(void)sig;
	set_or_get_last_ctrl_c(1, 1);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sig_hundler__ctrl_c__after_readline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	check_ctrl_c_and_reset_checker_value(t_shell *shell)
{
	if (set_or_get_last_ctrl_c(0, 1) == 1)
		shell->exit_status = 1;
	set_or_get_last_ctrl_c(1, 0);
}
