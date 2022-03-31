/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:42 by adouib            #+#    #+#             */
/*   Updated: 2022/03/31 21:35:20 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

// export_cmd to add env variables
// void export_cmd()
// {

// }

// void	env_cmd(t_shell *data)
// {
// 	while (data->envp)
// 	{
// 		printf("%s=%s\n", data->envp->key, data->envp->value);
// 		data->envp = data->envp->next;
// 	}
// }

void	pwd_cmd(void)
{
	char	*buf;

	buf = NULL;
	getcwd(buf, 0);
	if (!buf)
		perror("Error happens!");
	printf("current dir => %s\n", buf);
	free(buf);
}

void	cd_cmd(char *next_path)
{
	if (chdir(next_path) == -1)
		perror("chdir error");

}

void	builtin_cmd_executor(char **cmd)
{
	if (!ft_strcmp(cmd[0], "cd"))
		cd_cmd(cmd[1]);
	else if (!ft_strcmp(cmd[0], "pwd"))
		pwd_cmd();
	else if (!ft_strcmp(cmd[0], "cd"))
		printf("still did not coded cd");
	// else if (!strcmp(cmd[0], "env"))
	// 	// env_cmd();
}

bool	is_builtin_cmd(char *cmd)
{
	int i = 0;
	char *builtins_cmds[5] = {"echo", "pwd", "cd", "env", NULL};
	while (builtins_cmds[i])
	{
		if (!ft_strcmp(builtins_cmds[i], cmd))
			return true;
		i++;
	}
	return false;
}
