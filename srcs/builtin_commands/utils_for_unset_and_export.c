/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_unset_and_export.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:17:13 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/15 00:50:40 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

bool	is_this_key_valid_as_var_key(char *str)
{
	if (*str == '\0')
		return (false);
	if (ft_isdigit(*str))
		return (false);
	while (*str)
	{
		if (ft_isalnum(*str) || *str == '_')
			str++;
		else
			return (false);
	}
	return (true);
}

void	put_not_a_valid_identifier_error(char *cmdname, char *str)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(cmdname, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier", 2);
	write(2, "\n", 1);
}
