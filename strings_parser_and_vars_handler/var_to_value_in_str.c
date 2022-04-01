/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_value_in_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:13:35 by jchakir           #+#    #+#             */
/*   Updated: 2022/03/30 21:00:38 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds_executor.c"

char	*ft_strjoin_with_char(char const *s, char c)
{
	char	*str;
	char	*save_str;

	if (! s)
		s = "";
	str = malloc(ft_strlen(s) + 2);
	if (! str)
		return (NULL);
	save_str = str;
	while (*s)
		*str++ = *s++;
	*str++ = c;
	*str = '\0';
	return (save_str);
}

bool	is_valid_char_in_var_name(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

char	*get_var_name__key_(char *src)
{
	char	*str;
	char	*temp_str;

	str = ft_strdup("");
	while (is_valid_char_in_var_name(*src))
	{
		temp_str = ft_strjoin_with_char(str, *src);
		free(str);
		str = temp_str;
		src++;
	}
	return (str);
}

char	*get_var_value_by_its_key(char *key, t_env *env)
{
	if (! *key)
		return (NULL);
	while (env)
	{
		if (! ft_memcmp(env->key, key, ft_strlen(key) + 1))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*find_var_and_replace_it(char **src, char *str, t_env *env, int exit_status)
{
	char	*temp_str;
	char	*str_exit_status;
	char	*var_key;
	char	*var_value;

	if (! **src)
		return (NULL);
	if (ft_isdigit(**src))
	{
		*src = *src + 1;
		return (NULL);
	}
	if (**src == '?')
	{
		str_exit_status = ft_itoa(exit_status);
		temp_str = ft_strjoin(str, str_exit_status);
		free(str_exit_status);
		*src = *src + 1;
		return (temp_str);
	}
	var_key = get_var_name__key_(*src);
	*src = *src + ft_strlen(var_key);
	var_value = get_var_value_by_its_key(var_key, env);
	free(var_key);
	if (! var_value)
		return (NULL);
	return (ft_strjoin(str, var_value));
}

char    *var_to_value_in_str(char *src, t_env *env, int exit_status)
{
    char    *temp_str;
    char    *str;

    str = NULL;
    while (*src)
    {
        if (*src == '$' && (ft_isalnum(*(str + 1)) || *(str + 1) == '_' || *(str + 1) == '?'))
		{
			src++;
			temp_str = find_var_and_replace_it(&src, str, env, exit_status);
			if (temp_str)
			{
				free(str);
				str = temp_str;
			}
		}
        else
		{
			temp_str = ft_strjoin_with_char(str, *src);
			free(str);
			str = temp_str;
			src++;
		}
    }
	return (str);
}

char	*strdup_from_to__address_(char *start, char *end)
{
	// copy str from (address) start to end (start included, end excluded)
	char	*str;
	char	*ptr;
	size_t	len;

	len = 0;
	if (! start || ! end || start >= end)
		return (NULL);
	ptr = start;
	while (ptr++ < end)
		len++;
	str = (char *)malloc(len + 1);
	if (! str)
		return (NULL);
	ptr = str;
	while (start < end)
		*str++ = *start++;
	*str = '\0';
	return (ptr);
}

char	*var_to_value_in__str__from_to__address_(char *start, char *end, t_env *env, int exit_status)
{
	// copy str from (address) start to end (start included, end excluded)
	char	*str;
	char	*vars_in_str;

	str = strdup_from_to__address_(start, end);
	if (! str)
		return (NULL);
	vars_in_str = var_to_value_in_str(str, env, exit_status);
	free(str);
	return (vars_in_str);
}
