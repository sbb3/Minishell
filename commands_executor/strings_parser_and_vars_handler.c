/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_parser_and_vars_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:02:24 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/30 21:31:15 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds_executor.h"

static char	*get__address__until_limiter(char *str, char limiter)
{
	char	*until_limiter;

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

static char	*squotes_dquotes_str_and_vars_hundler(char *str, t_env *env, int exit_status)
{
	int		str_type;
	char	limiter;
	char	*end_str;
	char	*final_str;
	char	*temp_final_str;
	char	*temp_ptr;

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
		end_str = get__address__until_limiter(str, *str);
		if (str_type == SQUOTES)
			temp_ptr = strdup_from_to__address_(str, end_str);
		else
			temp_ptr = var_to_value_in__str__from_to__address_(str, end_str, env, exit_status);
		temp_final_str = ft_strjoin(final_str, temp_ptr);

		free(temp_ptr);
		free(final_str);
		final_str = temp_final_str;
		str = end_str;

		if (*str)
			str++;
	}
	return (final_str);
}

void	strings_parser_and_vars_handler(t_shell *shell)
{
	t_component	*component;
	int			index;

	index = 0;
	while (index < shell->parts_count)
	{
		component = shell->separator[index];
		while (component)
		{
			component->final_content = squotes_dquotes_str_and_vars_hundler(component->content, shell->envp, shell->exit_status);
			component = component->next;
		}
		index++;
	}
}
