/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:59:00 by adouib            #+#    #+#             */
/*   Updated: 2022/04/11 06:53:30 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "source.h"
# include "../srcs/commands_executor/commands_executor.h"
# include "../srcs/vars_handler/vars_handler.h"

# define INITIAL 200


// ERROR FUNCTIONS
void		ft_error(int c);
void		ft_error2(int c);
int			syntax_error(char *s);
void		quit(char *s, int errornum);
void		exit_if_null(void *p, char *message);

// PARSING
void		parser(t_shell *data);
char		**tokenizer(char *s, int *start);
char		*get_token(char *s, int *lastpos);
void		alloc_init(t_shell *data);
void		envinit(t_shell *data);
void		phasezero(t_shell *data);
void		phaseone(t_shell *data);
char		**ft_realloc_and_copy(char **tokens, size_t size, size_t tkns_len);
char		*pipehelper(int *from, int *lastpos);
void		redirectionhelper(char *s, int *to);
int			skip_redirection(int token_type);
int			gettoken_helper(char *token, int to, int *lastpos);
void		gettoken_helper2(char *token, int *end);
void		phaseone_helper(t_shell *data, int *k, int type1, int type2);
void		localhelper2(int *dqstate, int sqstate);
void		localhelper3(int *sqstate, int dqstate);

// CHECK
int			check(char *input);
int			check_redir(char *s, int i, char c);
int			check_pipe(char *s, int i);
void		quotescheck(char c, int *dqstate, int *sqstate);
int			check_redirec(char *s, int i);
void		check_helper1(int *dq);
void		check_helper2(int *sq);
int			another_helper(int *count, int whitespace);

// UTILS FUNCTIONS 1
int			isprintable(int c);
char		*ft_strcut_from_to(char *s, int from, int to);
t_component	*ft_lstnew(char *content, int tkn_type);
void		ft_lstadd_back(t_component **lst, t_component *new);
// int			ft_strcmp(char *s1, char *s2);
t_env		*lstinit(char *key, char *value);
void		pushback(t_env **head, t_env *new);

// UTILS FUNCTIONS 2
int			pipes_count(char *input);
int			*token_recognition(t_shell *data);
int			count(char *s[]);
int			quotes_count(char *s, int start, char c);
void		quoteshelper(char *s, int *to, char c);
void		set_null(t_shell *data);
char		*getkey(char *s);
void		reset_memory(t_shell *data);
void		ft_free(char **tokens, size_t tkns_len);
int			iswhitespace(char c);
void		if_c_else_k(char *c, char *k, int *dqstate, int *sqstate);
void		skipspaces(char *s, int *pos, int *space);
void		skipspaces2(char *s, int *pos, int *space);
t_shell		*init(void);
int			check_helper(char *s, int i, int dqstate, int sqstate);
int			check_redir_helper(char *s, int i);
char		*shlvl_helper(char *value);


#endif
