/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_parser_and_vars_handler.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:43:37 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/02 08:42:17 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_PARSER_AND_VARS_HANDLER_H
# define STRINGS_PARSER_AND_VARS_HANDLER_H


# include "../source/source.h"


# define FORBIDDEN_CHARS "\\;&|><"




enum e_str_types
{
	SINGLE_Q,
	DOUBLE_Q,
	SIMPLE_STR,
};



bool	quotes_and_forbidden_chars_checker(t_shell *shell);
char    *var_to_value_in_str(char *src, t_env *env, int exit_status, int *extra_param);
char	*strdup_from_to__address_(char *start, char *end);
bool	strings_parser_and_vars_handler(t_shell *shell);
char	*var_to_value_in__str__from_to__address_(char *start, char *end, t_env *env, int exit_status, int *extra_param);



#endif
