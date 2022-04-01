/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:03 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/01 11:25:04 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free_2D_pointer(char *ptr_2D[])
{
    int i;

    i = 0;
    if (ptr_2D)
    {
        while (ptr_2D[i])
            free(ptr_2D[i++]);
        free(ptr_2D);
    }
}

void ft_free_perror_exit(char **ptr2D_1, char **ptr2D_2, char *ptr1D,\
						    char const *error_str)
{
	ft_free_2D_pointer(ptr2D_1);
	ft_free_2D_pointer(ptr2D_2);
	free(ptr1D);
	perror(error_str);
	exit (EXIT_FAILURE);

}

void ft_put_custom_error(char const *str_error1, char const *str_error2)
{
    if (str_error1)
    	ft_putstr_fd(str_error1, 2);
    if (str_error2)
	    ft_putstr_fd(str_error2, 2);
    if (str_error1 || str_error2)
        write(2, "\n", 1);
}
