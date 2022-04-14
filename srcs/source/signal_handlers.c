/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:12:27 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/13 21:36:55 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "source_.h"

void	sig_handler_ctrl(int sig)
{
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGINT)
		return ;
	
}
