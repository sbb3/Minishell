/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__pwd_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:07:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 22:49:24 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

void	builtin_cmd__pwd_(char **args, int outfd)
{
	char	buff[251];
	char	*cwd;

	(void)args;
	// if (args[0])
	// {
	// 	put_custom_error("pwd: ", "too many arguments");
	// 	return ;
	// }
	cwd = getcwd(buff, 251);
	if (cwd == NULL)
	{
		perror("pwd");
		return ;
	}
	if (outfd > 0)
	{
		write(outfd, buff, ft_strlen(buff));
		write(outfd, "\n", 1);
	}
}


// int main(void)
// {
// 	char	*args[2] = {NULL, NULL};
// 	builtin_cmd__pwd_(args, 1);
// 	return 0;
// }

