/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:47 by adouib            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/07 03:01:41 by jchakir          ###   ########.fr       */
=======
/*   Updated: 2022/04/07 02:57:13 by adouib           ###   ########.fr       */
>>>>>>> de00b4885ad0005910775a4b1cf1cd1083b07b85
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
