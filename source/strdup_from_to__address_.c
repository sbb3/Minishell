/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_from_to__address_.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:26:50 by jchakir           #+#    #+#             */
/*   Updated: 2022/04/05 18:27:26 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

char	*strdup_from_to__address_(char *start, char *end)
{
	// copy str from (address) start to end (start included, end excluded)
	char	*str;
	char	*ptr;
	size_t	len;

	len = 0;
	if (! start || ! end || start > end)
		return (NULL);
	ptr = start;
	while (ptr++ < end)
		len++;
	str = (char *)malloc(len + 1);
	ptr = str;
	while (start < end)
		*str++ = *start++;
	*str = '\0';
	return (ptr);
}
