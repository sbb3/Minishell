/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:47 by adouib            #+#    #+#             */
/*   Updated: 2022/04/12 23:41:49 by jchakir          ###   ########.fr       */
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

char	*prompt(void)
{
	char	*input;
	int		non_stop;

	non_stop = 1;
	while (non_stop)
	{
		input = readline("🤙 ");
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
	t_shell	*shell;

	shell = init();
	envinit(shell);
	while (21)
	{
		shell->prompt_input = prompt();
		parser(shell);
		if (quotes_and_forbidden_chars_checker(shell))
		{
			strings_parser_and_vars_handler(shell);
			commands_executor(shell);
		}
		free_all_unneeded_data(shell);
		// free(shell->prompt_input);
		// system("leaks minishell");
	}
	return (0);
}
