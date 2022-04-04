/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:11 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/03 23:58:06 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c > 8 && c < 14)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str) && res < LONG_MAX)
		res = res * 10 + *str++ - 48;
	if (res > LONG_MAX)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (sign * (int)res);
}
