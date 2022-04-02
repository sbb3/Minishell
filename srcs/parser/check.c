/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:20:36 by adouib            #+#    #+#             */
/*   Updated: 2022/04/02 18:31:59 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	check_pipe(char *s, int i)
{
	int	count;
	int	ws;

	count = 1;
	ws = 0;
	if ((s[0] == '|') || (s[i] == '|' && s[i + 1] == '\0'))
		return (syntax_error("Syntax Error!"));
	while (s[i])
	{
		skipspaces2(s, &i, &ws);
		if (s[i] == '|')
		{
			if (count >= 2 || ws != 0)
				return (syntax_error("Syntax Error!"));
			count++;
		}
		else if (ws != 0 && s[i + 1] == '\0' && !isprintable(s[i]))
			return (syntax_error("Syntax Error!"));
		else if (s[i] != '|')
			return (1);
		i++;
	}
	return (1);
}

int	check_redir(char *s, int i, char c)
{
	int	count;
	int	ws;

	count = 1;
	ws = 0;
	if (!check_redir_helper(s, i))
		return (syntax_error("Syntax Error!"));
	while (s[i])
	{
		skipspaces(s, &i, &ws);
		if (s[i] == c)
		{
			if (!another_helper(&count, ws))
				return (syntax_error("Syntax Error!"));
		}
		else if ((ws != 0 && s[i + 1] == '\0' && !isprintable(s[i])) || \
			(s[i] == '|' && ws != 0))
			return (syntax_error("Syntax Error!"));
		else if (s[i] != c)
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
		else
			if (!check_helper(s, i, dqstate, dqstate))
				return (0);
	}
	if (dqstate || sqstate)
		return (syntax_error("Quotes Error!"));
	return (1);
}

/*
 handle hardcoded arrays
 check more errors
 handle leaks
//  handle realloc function
//  handle norm (header file)
//  handle exit quotes in check function
//  ignore whitespaces in check < > |


// fzdsz|dcxz|sdaf"|""||||" sdafasdf   => realloc
// fzdsz|dcxz|sdaf"|""||||" sdafasdf
// fzdsz|dcxz|sdaf"|""||||" sdafasdf5 er fefef
// fzdsz|dcxz|sdaf'"fxg|'"xfd"   => realloc
// dfgsgd || fsgs

< whitespace
< a
sdgf < | sd
sdf > a > d
dsfd > a > d <f < t > l > y < s


echo $'$dfgdf'"$user"
echo '$dfgd'
echo "dfg'$d'f"dfgdf

echo $dfgdfg

echo |      space => error

; & \
ls <| ls
*/