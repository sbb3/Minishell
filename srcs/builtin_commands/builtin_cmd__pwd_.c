/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__pwd_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:07:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/11 01:25:33 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

void	builtin_cmd__pwd_(t_builtin_cmd_data *data)
{
	char	buff[251];
	char	*cwd;

	data->ext_stts = 0;
	cwd = getcwd(buff, 251);
	if (cwd == NULL)
	{
		custom_msg_then_perror("pwd");
		return ;
	}
	ft_putendl_fd(buff, data->outfd);
}
