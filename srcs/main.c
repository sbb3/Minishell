/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:47 by adouib            #+#    #+#             */
/*   Updated: 2022/03/30 22:46:25 by adouib           ###   ########.fr       */
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
	t_shell	data;

	envinit(&data);
	/*
	while (data.envp)
	{
		printf("%s=%s\n", data.envp->key, data.envp->value);
		data.envp = data.envp->next;
	}
	*/
	while (21)
	{
		data.prompt_input = prompt();
		parser(&data);
		printing(&data);
		// expander();

	}
	return (0);
}
