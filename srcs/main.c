/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:47 by adouib            #+#    #+#             */
/*   Updated: 2022/04/14 05:53:06 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

// int	set_or_get_last_ctrl_c(int setter, int new_value)
// {
// 	static int	is_last_ctrl_c;

// 	if (setter)
// 		is_last_ctrl_c = new_value;
// 	// printf("i m clicked: %d\n", new_value);
// 	return (is_last_ctrl_c);
// }

int	is_last_ctrl_c;

static void	free_all_unneeded_data(t_shell *shell)
{
	t_component	*this_c;
	t_component	*next_c;
	int			index;

	index = 0;
	while (index < shell->parts_count)
	{
		this_c = shell->separator[index];
		while (this_c)
		{
			next_c = this_c->next;
			free(this_c->content);
			free(this_c);
			this_c = next_c;
		}
		index++;
	}
	free(shell->separator);
}

static void	sig_hundler__ctrl_c__before_readline(int sig)
{
	(void)sig;
	is_last_ctrl_c = 1;
	// set_or_get_last_ctrl_c(1, 1);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	sig_hundler__ctrl_c__after_readline(int sig)
{
	(void)sig;
	is_last_ctrl_c = 1;
	// set_or_get_last_ctrl_c(1, 1);
	write(1, "\n", 1);
}

char	*prompt(struct sigaction *ctrl_c)
{
	char	*input;
	int		non_stop;

	non_stop = 1;
	while (non_stop)
	{
		is_last_ctrl_c = 0;
		ctrl_c->sa_handler = sig_hundler__ctrl_c__before_readline;
		sigaction(SIGINT, ctrl_c, NULL);
		input = readline("MiniShell: $🤙 ");
		ctrl_c->sa_handler = sig_hundler__ctrl_c__after_readline;
		sigaction(SIGINT, ctrl_c, NULL);
		if (!input)
			exit(0);
		if (input && *input)
			add_history(input);
		if (!(*input))
		{
			free(input);
			continue ;
		}
		else if (check(input))
			non_stop = 0;
		else
			free(input);
	}
	return (input);
}

int	main(void)
{
	t_shell				*shell;
	struct sigaction	ctrl_back_slash;
	struct sigaction	ctrl_c;

	ctrl_back_slash.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &ctrl_back_slash, NULL);
	ctrl_c.sa_flags = SA_RESTART;
	shell = init();
	envinit(shell);
	while (1337)
	{
		shell->prompt_input = prompt(&ctrl_c);
		if (is_last_ctrl_c)
			shell->exit_status = 130;
		parser(shell);
		if (quotes_and_forbidden_chars_checker(shell))
		{
			strings_parser_and_vars_handler(shell);
			commands_executor(shell);
		}
		free_all_unneeded_data(shell);
		if (is_last_ctrl_c)
			shell->exit_status = 130;
	}
	return (0);
}
