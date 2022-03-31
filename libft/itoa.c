/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:41:13 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/19 18:48:11 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(long int num)
{
	int	l;

	l = 0;
	while (num / 10)
	{
		num = num / 10;
		l++;
	}
	return (l + 1);
}

static	char	*ft_setstring(long nbr, int is_negative)
{
	int		len;
	char	*str;

	len = ft_len(nbr);
	str = malloc((len + is_negative + 1) * sizeof(char));
	if (! str)
		return (str);
	else
		str += len + is_negative;
	*str-- = 0;
	while (nbr / 10)
	{
		*str-- = nbr % 10 + '0';
		nbr /= 10;
	}
	*str = nbr + '0';
	if (is_negative)
		*(--str) = '-';
	return (str);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		is_negative;
	long	nbr;

	nbr = num;
	is_negative = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		is_negative = 1;
	}
	str = ft_setstring(nbr, is_negative);
	return (str);
}
