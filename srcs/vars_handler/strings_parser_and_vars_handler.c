/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_parser_and_vars_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:02:24 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/07 01:06:40 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars_handler.h"

static char	*get__address__until_limiter(char *str, char limiter)
{
	while (*str)
	{
		if (limiter == '\0' && (*str == '"' || *str == '\''))
			return (str);
		if (*str == limiter)
			return (str);
		str++;
	}
	return (str);
}

static char	*squotes_dquotes_and_vars_hundler(char *str, t_env *env, int exit_status)
{
	int		str_type;
	char	limiter;
	char	*end_str;
	char	*final_str;
	char	*temp_final_str;
	char	*temp_ptr;
	int 	extra_param[2];

	final_str = ft_strdup("");
	while (*str)
	{
		if (*str == '"')
		{
			str_type = DOUBLE_Q;
			limiter = '"';
			str++;
		}
		else if (*str == '\'')
		{
			str_type = SINGLE_Q;
			limiter = '\'';
			str++;
		}
		else
		{
			str_type = SIMPLE_STR;
			limiter = '\0';
		}
		end_str = get__address__until_limiter(str, limiter);

		extra_param[0] = str_type;
		extra_param[1] = *end_str;

		if (str_type == SINGLE_Q)
			temp_ptr = strdup_from_to__address_(str, end_str);
		else
			temp_ptr = var_to_value_in__str__from_to__address_(str, end_str, env, exit_status, extra_param);
		temp_final_str = ft_strjoin(final_str, temp_ptr);

		free(temp_ptr);
		free(final_str);
		final_str = temp_final_str;

		str = end_str;

		if (limiter)
			str++;
	}
	return (final_str);
}

static void	strings_parser_and_vars_handler__in_components_(t_component *component, t_env *envp, int exit_status)
{
	char		*str;

	while (component)
	{
		if (ft_strchr(component->content, '"') || ft_strchr(component->content, '\''))
			str = squotes_dquotes_and_vars_hundler(component->content, envp, exit_status);
		else
			str = var_to_value_in_str(component->content, envp, exit_status, NULL);

		free(component->content);
		component->content = str;
		component = component->next;
	}
}

bool	strings_parser_and_vars_handler(t_shell *shell)
{
	t_component	*component;
	int			index;

	if (quotes_and_forbidden_chars_checker(shell) == false)
	{
		put_custom_error(NULL, QUOTES_OR_FORB_CHAR_ERROR);
		return (false);
	}

	index = 0;
	while (index < shell->parts_count)
	{
		component = shell->separator[index];
		strings_parser_and_vars_handler__in_components_(component, shell->envp, shell->exit_status);
		index++;
	}
	return (true);
}
