/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:26 by adouib            #+#    #+#             */
/*   Updated: 2022/04/11 23:46:12 by adouib           ###   ########.fr       */
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

char	*shlvl_helper(char *value)
{
	int		num;

	num = ft_atoi(value);
	num++;
	free(value);
	return (ft_itoa(num));
}

void	envinit(t_shell *data)
{
	t_env	*newnode;
	char	*key;
	char	*value;
	int		i;
	int		envlen;

	envlen = count(environ);
	// data->envs = malloc(sizeof(int *) * (envlen + 1));
	// exit_if_null(data->envs, "Allocation failed");
	data->envp = NULL;
	i = -1;
	while (environ[++i])
	{
		// data->envs[i] = ft_strdup(environ[i]);
		key = getkey(environ[i]);
		value = ft_strdup(getenv(key));
		// if (!ft_memcmp(key, "SHLVL", 6))
		// 	value = shlvl_helper(value);
		newnode = lstinit(key, value);
		pushback(&data->envp, newnode);
	}
	// data->envs[i] = NULL;
}
