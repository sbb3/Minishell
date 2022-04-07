/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__echo_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:22:35 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 17:32:21 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

static void	set__new_line__args_as_null(char **args)
{
	char	*str;

	while (*args)
	{
		str = *args;

		
		if (*str == '-')
			str++;
		while (*str)
		{
			if (*str != 'n')
				return ;
			str++;
		}
		if (*str == '\0')
			*args = NULL;
		args++;
	}
}

void	builtin_cmd__echo_(char **args, int outfd)
{
	int	index;
	int	len;

	if (args[0] == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	len = 0;
	while (args[len])
		len++;
	set__new_line__args_as_null(args);
	index = 0;
	while (index < len)
	{
		if (args[index])
		{
			write(outfd, args[index], ft_strlen(args[index]));
			if (index < len - 1)
				write(outfd, " ", 1);
			else if (args[0])
				write(outfd, "\n", 1);
		}
		index++;
	}
}
