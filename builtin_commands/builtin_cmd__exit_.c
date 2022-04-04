/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd__exit_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:02:16 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/04 01:36:10 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_commands.h"

static int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c > 8 && c < 14)
		return (1);
	return (0);
}

static bool	check_this_string_is_numerical(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (false);
		str++;
	}
	return (true);
}

static bool	check_this_arg_is_int(char *str, int res)
{
	while (ft_isspace(*str))
		str++;
	if (res == -1)
	{
		if (*str != '-')
			return (false);
	}
	else if (res == 0)
	{
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
			if (*str++ != '0')
				return (false);
	}
	return (true);
}

static void	write_num_arg_required_error_then_exit_255(char *str)
{
	write(2, "exit: ", 6);
	put_custom_error(str, ": numeric argument required");
	exit(255);
}

void	builtin_cmd__exit_(char	**args)
{
	int	result;

	write(2, "exit\n", 5);
	if (args[0] == NULL)
		exit (0);

	if (check_this_string_is_numerical(args[0]) == false)
		write_num_arg_required_error_then_exit_255(args[0]);

	result = ft_atoi(args[0]);

	if (check_this_arg_is_int(args[0], result) == false)
		write_num_arg_required_error_then_exit_255(args[0]);

	if (args[1])
	{
		put_custom_error("exit: ", "too many arguments");
		return ;
	}
	exit (result);
}

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	builtin_cmd__exit_(argv + 1);
// 	printf("non exit\n");
// 	return 0;
// }
