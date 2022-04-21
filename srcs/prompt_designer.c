/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_designer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:18:31 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/21 19:07:13 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/minishell.h"

static void	print_user_from_envp(t_env *envp)
{
	while (envp)
	{
		if (ft_strcmp(envp->key, "USER") == 0)
		{
			printf("\n╭─"BGRN"%s"CRESET, envp->value);
			return ;
		}
		envp = envp->next;
	}
	printf("\n╭─user");
}

void	prompt_string__designed__(t_shell *shell)
{
	char	buffer[251];

	print_user_from_envp(shell->envp);
	if (shell->exit_status == 0)
		printf("@"BYEL"localhost"RESET":["BBLU"%s"RESET"] < "BGRN"%d"RESET" >\n", getcwd(buffer, 251), shell->exit_status);
	else
		printf("@"BYEL"localhost"RESET":["BBLU"%s"RESET"] < "BRED"%d"RESET" >\n", getcwd(buffer, 251), shell->exit_status);
	printf("╰─➤$ ");
}
