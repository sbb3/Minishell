/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:13:54 by adouib            #+#    #+#             */
/*   Updated: 2022/03/30 23:29:23 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	if_c_else_k(char *c, char *k, int *dqstate, int *sqstate)
{
	*dqstate = 0;
	*sqstate = 0;
	if (*c == '"')
		*k = '\'';
	else if (*c == '\'')
		*k = '"';
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	string_size;
	size_t	i;

	string_size = ft_strlen(s);
	buf = (char *) malloc(sizeof(char) * string_size + 1);
	if (!buf)
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int tokens_count(char *s[])
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strcut_from_to(char *s, int from, int to)
{
	char *buf;
	int i;

	buf = (char *)malloc(sizeof(char) * (to - from) + 1);
	if (!buf)
		return (0);
	i = 0;
	while (from < to)
	{
		buf[i] = s[from];
		from++;
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

// int quotes_count(char *s, int start, char c)
// {
// 	int count;
// 	int state = 0;
// 	count = 0;
// 	//  && s[start] != ' '
// 	while (s[start])
// 	{
// 		if (s[start] == c)
// 		{
// 			if (!state)
// 				state = 1;
// 			else
// 				state = 0;
// 			count++;
// 			if (count == 2)
// 				return count;
// 		}
// 		if (s[start] == ' ' && !state)
// 			break;
// 		start++;
// 	}
// 	return (count);
// }

// char *dollar_expanding(char *s, int *usd_pos)
// {
// 	char *shit;
// 	char *key;
// 	char *value;
// 	int char_after_usd = (*usd_pos) + 1;
// 	int from = *usd_pos;
// 	int k = 0;
// 	char *c;
// 	int to;
// 	int to_save;
// 	int key_last_char_pos;
// 	char *backup = ft_strcut_from_to(s, 0, *usd_pos);
// 	char **envp = env_init();
// 	char *new_s;
// 	int slen = strlen(s);
// 	new_s = ft_strcut_from_to(s, 0, *usd_pos);


// 	to = *usd_pos;
// 	while (s[to] && s[to] != ' ')
// 	{
// 		from = to + 1;

// 		if (s[to] == '$' && s[to + 1] != '.')
// 		{
// 			to++;
// 			while (s[to] && s[to] != ' ' && s[to] != '.' && s[to] != '$')
// 				to++;
// 				// dprintf(2, "from %d\n", from);

// 			key = ft_strcut_from_to(s, from, to);
// 				// dprintf(2, "key %s\n", key);
// 			value = get_path(key, envp);
// 			// value = getenv(key);
// 			if (!value)
// 				value = strdup("");
// 			new_s = ft_strjoin(new_s, value);
// 				// dprintf(2, "new_s %s\n", new_s);
// 				// dprintf(2, "to3 %d\n", to);
// 			to_save = to;
// 		}
// 		else
// 		{
// 			from = to;
// 				// dprintf(2, "to %d\n", to);
// 			c = ft_strcut_from_to(s, from, to + 1);
// 			new_s = ft_strjoin(new_s, c);
// 				// dprintf(2, "new_s %s\n", new_s);
// 			to++;

// 		}
// 	}

// 	(*usd_pos) = to_save;
// 		// dprintf(2, "usd_pos %d\n", *usd_pos);
// 	// join what left from string
// 	if (s[to])
// 	{
// 		char *left_ori = ft_strcut_from_to(s, to, slen);
// 		new_s = ft_strjoin(new_s, left_ori);
// 				// dprintf(2, "new_s %s\n", new_s);
// 	}
// 	return new_s;
// }

int lencutted(char *s, char c)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
			count++;
	}
	return (count);
}

char *cut(char *tkn)
{
	char buf[2000];
	int i;
	int k;
	int dq_state = 0;
	int sq_state = 0;

	i = -1;
	k = -1;
	while (tkn[++i])
	{
		if (tkn[i] == '"' && !sq_state)
		{
			if (!dq_state)
				dq_state = 1;
			else
				dq_state = 0;
		}
		else if (tkn[i] == '\'' && !dq_state)
		{
			if (!sq_state)
				sq_state = 1;
			else
				sq_state = 0;
		}
		else
			buf[++k] = tkn[i];
	}
	buf[++k] = '\0';
	return (strdup(buf));
}

int	intlen(long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}


int	skip_redirection(int token_type)
{
	if (token_type == LESS || token_type == HEREDOC || \
		token_type == GREATER || token_type == APPEND)
		return (1);
	return (0);
}

void	set_null(t_shell *data)
{
	int	i;

	i = -1;
	while (++i < data->parts_count)
		(data->separator)[i] = NULL;
}

int	gettoken_helper(char *token, int to, int *lastpos)
{
	if (*token == '\0')
	{
		if (ft_strlen(token) == to)
		{
			*lastpos = to;
			return (0);
		}
		else
		{
			*lastpos = to + 1;
			return (0);
		}
	}
	else
		*lastpos = to;
	return (1);
}

void	gettoken_helper2(char *token, int *end)
{
	int	dquotes_state;
	int	squotes_state;
	int	to;

	dquotes_state = 0;
	squotes_state = 0;
	to = (*end);
	while (token[to])
	{
		if (token[to] == DOUBLEQUOTE)
			quoteshelper(token, &to, DOUBLEQUOTE);
		if (token[to] == SINGLEQUOTE)
			quoteshelper(token, &to, SINGLEQUOTE);
		if (token[to] == ' ')
			break ;
		if (token[to] == '<' || token[to] == '>' || token[to] == '|')
			break ;
		to++;
	}
	(*end) = to;
}

void	printing(t_shell *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->parts_count)
	{
		j = -1;
		while (data->separator[i])
		{
			printf("%s\n", data->separator[i]->content);
			printf("%d\n", data->separator[i]->type);
			data->separator[i] = data->separator[i]->next;
		}
	}
}

void	reset_memory(t_shell *data)
{
	int	i;

	if (data->tokens)
	{
		i = -1;
		while (data->tokens[++i])
			free(data->tokens[i]);
		free(data->tokens);
	}
	if (data->tkns_recognition)
	{
		free(data->tkns_recognition);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((s1[i] - s2[i]));
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

void	phaseone_helper(t_shell *data, int *k, int not, int type1, int type2)
{
	int	i;

	i = (*k);
	if (!not)
	{
		data->tkns_recognition[i] = type1;
		data->tkns_recognition[++i] = type2;
	}
	else
		data->tkns_recognition[i] = COMMAND;
	(*k) = i;
}

void	localhelper(int *state)
{
	if (!(*state))
		(*state) = 1;
	else
		(*state) = 0;
}

void	localhelper2(int *dqstate, int sqstate)
{
	if (!(*dqstate) && !sqstate)
		(*dqstate) = 1;
	else
		(*dqstate) = 0;
}

void	localhelper3(int *sqstate, int dqstate)
{
	if (!(*sqstate) && !dqstate)
		(*sqstate) = 1;
	else
		(*sqstate) = 0;
}

void	phasetwo_helper(t_shell *data, int i)
{
	int	dq_state;
	int	sq_state;
	int	j;

	dq_state = 0;
	sq_state = 0;
	j = -1;
	while (data->tokens[i][++j])
	{
		if (data->tokens[i][j] == '\"' && !sq_state)
			localhelper(&dq_state);
		else if (data->tokens[i][j] == '\'')
			localhelper(&sq_state);
		else if (data->tokens[i][j] == '$' && sq_state)
		{
			data->tkns_recognition[i] = SQ_USD;
			break ;
		}
		else if ((data->tokens[i][j] == '$' && dq_state) || \
			(data->tokens[i][j] == '$' && !sq_state))
			data->tkns_recognition[i] = USD;
	}
}

void	skipspaces(char *s, int *pos, int *space)
{
	int	i;
	int	whitespace;

	i = (*pos);
	whitespace = (*space);
	while (iswhitespace(s[i]))
	{
		whitespace++;
		i++;
	}
	*pos = i;
	*space = whitespace;
}


/* STRIPPING QUOTES FUNCTIONS
// data->tokens[i] = strip_quotes(tkn, data->tkns_recognition[i]);
char *strip_quotes(char *tkn, int tkn_type)
{
	char buf[2000];
	int i;
	int k;
	int dq_state = 0;
	int sq_state = 0;

	i = -1;
	k = -1;
	if (tkn_type == ARGS || tkn_type == USD)
	{
		while (tkn[++i])
		{
			if (tkn[i] == '"' && !sq_state)
			{
				if (!dq_state)
					dq_state = 1;
				else
					dq_state = 0;
			}
			else if (tkn[i] == '\'' && !dq_state)
			{
				if (!sq_state)
					sq_state = 1;
				else
					sq_state = 0;
			}
			else
				buf[++k] = tkn[i];
		}
		buf[++k] = '\0';
		return (strdup(buf));
	}
	else
		return (tkn);
}
*/