/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_and_forbidden_chars_checker.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:55:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 01:06:34 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars_handler.h"

static bool	is_this_char_forbidden_outside_quotes(char c)
{
	char	*forbidden_chars;

	forbidden_chars = FORBIDDEN_CHARS;
	while (*forbidden_chars)
	{
		if (*forbidden_chars == c)
			return (true);
		forbidden_chars++;
	}
	return (false);
}

static bool	quotes_error_and_forbidden_chars_checker(char *str)
{
	char	limiter;
	bool	is_closed;

	is_closed = true;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			if (is_closed)
			{
				limiter = *str;
				is_closed = false;
			}
			else if (limiter == *str)
				is_closed = true;
		}
		if (is_closed && is_this_char_forbidden_outside_quotes(*str))
			return (false);
		str++;
	}
	return is_closed;
}

bool	quotes_and_forbidden_chars_checker(t_shell *shell)
{
	t_component	*component;
	int			i;

	i = 0;
	while (i < shell->parts_count)
	{
		component = shell->separator[i];
		while (component)
		{
			if (quotes_error_and_forbidden_chars_checker(component->content) == false)
				return (false);
			component = component->next;
		}
		i++;
	}
	return (true);
}
