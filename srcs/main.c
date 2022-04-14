/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:47 by adouib            #+#    #+#             */
/*   Updated: 2022/04/14 03:25:36 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

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
	// rl_replace_line("");
	rl_on_new_line();
	rl_redisplay();
}

static void	sig_hundler__ctrl_c__after_readline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

char	*prompt(struct sigaction *ctrl_c)
{
	char	*input;
	int		non_stop;

	non_stop = 1;
	while (non_stop)
	{
		ctrl_c->sa_handler = sig_hundler__ctrl_c__before_readline;
		input = readline("MiniShell: $🤙 ");
		ctrl_c->sa_handler = sig_hundler__ctrl_c__after_readline;

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

	ctrl_c.sa_handler = sig_hundler__ctrl_c__before_readline;
	ctrl_c.sa_flags = SA_RESTART;
	sigaction(SIGINT, &ctrl_c, NULL);

	shell = init();
	envinit(shell);
	while (1337)
	{
		shell->prompt_input = prompt(&ctrl_c);
		parser(shell);
		if (quotes_and_forbidden_chars_checker(shell))
		{
			strings_parser_and_vars_handler(shell);
			commands_executor(shell);
		}
		free_all_unneeded_data(shell);
	}
	return (0);
}
