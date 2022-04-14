/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:00:44 by adouib            #+#    #+#             */
/*   Updated: 2022/04/14 04:52:55 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "source.h"
# include "../srcs/commands_executor/commands_executor.h"
# include "../srcs/vars_handler/vars_handler.h"
# include "../srcs/parser/parser.h"



void rl_replace_line (const char *text, int clear_undo);



#endif
