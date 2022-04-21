/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:43:55 by adouib            #+#    #+#             */
/*   Updated: 2022/04/21 02:50:58 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	syntax_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}

void	exit_if_null(void *p, char *message)
{
	if (!p)
	{
		ft_putendl_fd(message, 2);
		exit(EXIT_FAILURE);
	}
}

void	quit(char *s, int errornum)
{
	ft_putendl_fd(s, 2);
	exit(errornum);
}
