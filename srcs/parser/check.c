/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:20:36 by adouib            #+#    #+#             */
/*   Updated: 2022/03/31 13:34:40 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	check_pipe(char *s, int i)
{
	int	count;
	int	space;

	count = 1;
	space = 0;
	if ((s[0] == '|') || (s[i] == '|' && s[i + 1] == '\0'))
		return (syntax_error("Syntax Error!"));
	while (s[i])
	{
		while (iswhitespace(s[i]) || s[i] == '<' || s[i] == '>')
		{
			space++;
			i++;
		}
		if (s[i] == '|')
		{
			if (count > 2 || space != 0)
				return (syntax_error("Syntax Error!"));
			count++;
		}
		if (s[i] != '|')
			return (1);
		i++;
	}
	return (1);
}

int	check_redir(char *s, int i, char c)
{
	int	count;
	int	whitespace;

	count = 1;
	whitespace = 0;
	if ((s[i] == '>' && s[i + 1] == '<') || (s[i] == '<' && s[i + 1] == '>'))
		return (syntax_error("Syntax Error!"));
	while (s[i])
	{
		skipspaces(s, &i, &whitespace);
		if (s[i] == c)
		{
			if (count > 2 || whitespace != 0)
				return (syntax_error("Syntax Error!"));
			count++;
		}
		if (whitespace != 0 && s[i + 1] == '\0')
			return (syntax_error("Syntax Error!"));
		if (s[i] != c)
			return (1);
		i++;
	}
	if (s[i] == '\0')
		return (syntax_error("Syntax Error!"));
	return (1);
}

int	check_redirec(char *s, int i)
{
	if (s[i] == LREDIR)
	{
		if (!check_redir(s, i, LREDIR))
			return (0);
	}
	else if (s[i] == RREDIR)
	{
		if (!check_redir(s, i, RREDIR))
			return (0);
	}
	return (1);
}

void	quotescheck(char c, int *dqstate, int *sqstate)
{
	if (c == '"')
	{
		if (!(*dqstate) && !(*sqstate))
			(*dqstate) = 1;
		else
			(*dqstate) = 0;
	}
	else if (c == '\'')
	{
		if (!(*sqstate) && !(*dqstate))
			(*sqstate) = 1;
		else
			(*sqstate) = 0;
	}
}

int	check(char *s)
{
	int	i;
	int	dqstate;
	int	sqstate;

	dqstate = 0;
	sqstate = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == DOUBLEQUOTE || s[i] == SINGLEQUOTE)
			quotescheck(s[i], &dqstate, &sqstate);
		else if (s[i] == LREDIR || s[i] == RREDIR)
		{
			if (!check_redirec(s, i))
				return (0);
		}
		else if ((s[i] == PIPE) && (!dqstate && !sqstate))
			if (!check_pipe(s, i))
				return (0);
	}
	if (dqstate || sqstate)
		return (syntax_error("Quotes Error!"));
	return (1);
}

/**
 handle hardcoded arrays
 check more errors
 handle realloc function
//  handle norm (header file)
 handle leaks
//  handle exit quotes in check function

//  ignore whitespaces in check < > |
*/