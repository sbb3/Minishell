/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:26 by adouib            #+#    #+#             */
/*   Updated: 2022/03/29 15:25:59 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

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

	data->envp = NULL;
	while (*environ)
	{
		key = getkey(*environ);
		value = getenv(key);
		newnode = lstinit(key, value);
		pushback(&data->envp, newnode);
		environ++;
	}
}
