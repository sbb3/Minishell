/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_custom_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:04:38 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/29 17:11:58 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds_executor.h"

void put_custom_error(char const *str_error1, char const *str_error2)
{
    if (str_error1)
    	ft_putstr_fd(str_error1, 2);
    if (str_error2)
	    ft_putstr_fd(str_error2, 2);
    write(2, "\n", 1);
}
