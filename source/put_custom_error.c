/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_custom_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:38 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/06 23:52:10 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"


void	ft_putstr_fd(char *s, int fd)
{
	if (! s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void put_custom_error(char *str_error1, char *str_error2)
{
    ft_putstr_fd(SHELL_NAME, 2);
    if (str_error1)
    	ft_putstr_fd(str_error1, 2);
    if (str_error2)
	    ft_putstr_fd(str_error2, 2);
    write(2, "\n", 1);
}

void    custom_msg_then_perror(char *str)
{
    ft_putstr_fd(SHELL_NAME, 2);
    perror(str);
}
