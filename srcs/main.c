/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:47 by adouib            #+#    #+#             */
/*   Updated: 2022/04/07 03:01:41 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

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
			continue ;
		else if (check(input))
			non_stop = 0;
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
		// printing(shell);

		if (quotes_and_forbidden_chars_checker(shell))
		{
			strings_parser_and_vars_handler(shell);
			commands_executor(shell);
		}
		// printf("\n");
		// system("leaks minishell");
		// printf("\n");
	}
	return (0);
}
