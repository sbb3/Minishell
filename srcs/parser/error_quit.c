/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:43:55 by adouib            #+#    #+#             */
/*   Updated: 2022/04/11 23:45:45 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	syntax_error(char *s)
{
	printf("%s\n", s);
	return (0);
}

void	exit_if_null(void *p, char *message)
{
	if (!p)
	{
		printf("%s\n", message);
		exit(EXIT_FAILURE);
	}
}

void	quit(char *s, int errornum)
{
	printf("%s\n", s);
	exit(errornum);
}
