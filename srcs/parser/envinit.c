/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:26 by adouib            #+#    #+#             */
/*   Updated: 2022/04/16 22:01:46 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*getkey(char *s)
{
	char	*key;
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '=')
			return (key = ft_strcut_from_to(s, 0, i));
	}
	return (0);
}

void	envinit(t_shell *data)
{
	t_env	*newnode;
	char	*key;
	char	*value;
	int		i;
	int		envlen;

	envlen = count(environ);
	data->envs = ft_calloc(envlen + 2, sizeof(char *));
	exit_if_null(data->envs, "Allocation failed");
	data->envp = NULL;
	i = -1;
	while (environ[++i])
	{
		data->envs[i] = ft_strdup(environ[i]);
		key = getkey(environ[i]);
		value = ft_strdup(getenv(key));
		newnode = lstinit(key, value);
		pushback(&data->envp, newnode);
	}
	shlvl_initializer(&data->envp, data->envs);
}
