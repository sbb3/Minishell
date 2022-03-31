/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:44 by adouib            #+#    #+#             */
/*   Updated: 2022/03/31 18:23:51 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*m_dest;
	const char	*m_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	m_dest = (char *) dest;
	m_src = (const char *) src;
	i = 0;
	while (i < n)
	{
		m_dest[i] = m_src[i];
		i++;
	}
	return ((char *) dest);
}

// size_t	malloc_size(void *p)
// {
// 	return ((size_t *) p)[-1];
// }

size_t getsize(void * p)
{
	size_t *in = p;
	if (in)
	{
		return in[-1];
	}
	return -1;
}

// void	*ft_realloc(void *p, size_t size)
// {
// 	void	*new;

// 	if (!p)
// 	{
// 		new = malloc(sizeof(p) * size);
// 		exit_if_null(new, "Allocation failed");
// 	}
// 	else
// 	{
// 		if (getsize(p) < size)
// 		{
// 			new = malloc(size);
// 			exit_if_null(new, "Allocation failed");
// 			ft_memcpy(new, p, malloc_size(p));
// 			free(p);
// 		}
// 		else
// 			new = p;
// 	}
// 	return (new);
// }

// void	*ft_realloc(void *p, size_t size)
// {
// 	size_t i;
// 	void *new = malloc(size);
// 	exit_if_null(new, "Allocation failed");
// 	// ft_memcpy(new, p, size);
	
// 	i = -1;
// 	while ()
// 	{
		
// 	}
	
	
// 	// free(p);
// 	return (new);
// }

char	**test(char **tokens, size_t size, size_t tkns_len)
{
	char	**new;
	size_t	y;

	new	= malloc(sizeof(char *) * size);
	exit_if_null(new, "Allocation failed");
	y = 0;
	while (y < tkns_len)
	{
		new[y] = ft_strdup(tokens[y]);
		y++;
	}
	// ft_free(tokens, tkns_len);
	return (new);
}

void	ft_free(char **tokens, size_t tkns_len)
{
	size_t	i;

	i = 0;
	while (i < tkns_len)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}