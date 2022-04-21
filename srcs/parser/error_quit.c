/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:43:55 by adouib            #+#    #+#             */
/*   Updated: 2022/04/21 21:32:54 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	syntax_error(char *s)
{
	put_custom_error(s, NULL);
	return (0);
}

void	exit_if_null(void *p, char *message)
{
	if (!p)
	{
		put_custom_error(message, NULL);
		exit(EXIT_FAILURE);
	}
}

void	quit(char *s, int errornum)
{
	put_custom_error(s, NULL);
	exit(errornum);
}
