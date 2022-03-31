/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:00:44 by adouib            #+#    #+#             */
/*   Updated: 2022/03/31 18:23:07 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

# define INITIAL 2

extern char	**environ;

enum e_id
{
	LESS,
	HEREDOC,
	GREATER,
	APPEND,
	INFILE,
	DELIMITER,
	OUTFILE,
	OUTFILE_APPEND,
	COMMAND,
	ARGS,
	DQUOTES,
	SQUOTES,
	USD,
	SQ_USD,
};

enum e_types
{
	LREDIR = '<',
	RREDIR = '>',
	DOUBLEQUOTE = '"',
	SINGLEQUOTE = '\'',
	PIPE = '|',
};

typedef struct s_shell
{
	struct s_component	**separator;
	struct s_env		*envp;
	char				**envs;
	char				*prompt_input;
	int					parts_count;
	int					exit_status;
	int					*tkns_recognition;
	int					start;
	char				**tokens;
	int					tokens_len;
	int					infile_fd;
	int					outfile_fd;
	int					*pids_and_pipefds;

}	t_shell;

typedef struct s_component
{
	char				*content;
	int					type;
	struct s_component	*next;
}	t_component;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// BUILTINS FUNCTIONS
bool		is_builtin_cmd(char *cmd);
void		builtin_cmd_executor(char **cmd);
void		cd_cmd(char *next_path);
void		pwd_cmd(void);
void		env_cmd(void);

// ERROR FUNCTIONS
void		ft_error(int c);
void		ft_error2(int c);
int			syntax_error(char *s);

// PARSING
void		parser(t_shell *data);
char		**tokenizer(char *s, int *start);
char		*get_token(char *s, int *lastpos);
void		alloc_init(t_shell *data);
void		envinit(t_shell *data);
void		phasezero(t_shell *data);
void		phaseone(t_shell *data);
void		phasetwo(t_shell *data);
char		*pipehelper(int *from, int *lastpos);
void		redirectionhelper(char *s, int *to);
int			skip_redirection(int token_type);
int			gettoken_helper(char *token, int to, int *lastpos);
void		gettoken_helper2(char *token, int *end);
void		phaseone_helper(t_shell *data, int *k, int type1, int type2);
void		phasetwo_helper(t_shell *data, int i);
void		localhelper(int *state);
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

// UTILS FUNCTIONS 1
int			ft_isalnum(int c);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strcut_from_to(char *s, int from, int to);
t_component	*ft_lstnew(char *content, int tkn_type);
void		ft_lstadd_back(t_component **lst, t_component *new);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(char *s, char c);
t_env		*lstinit(char *key, char *value);
void		pushback(t_env **head, t_env *new);

// UTILS FUNCTIONS 2
int			pipes_count(char *input);
int			*token_recognition(t_shell *data);
int			count(char *s[]);
int			quotes_count(char *s, int start, char c);
void		quoteshelper(char *s, int *to, char c);
void		set_null(t_shell *data);
void		exit_if_null(void *p, char *message);
char		*getkey(char *s);
void		reset_memory(t_shell *data);
int			iswhitespace(char c);
void		if_c_else_k(char *c, char *k, int *dqstate, int *sqstate);
void		skipspaces(char *s, int *pos, int *space);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		malloc_size(void *p);
void	*ft_realloc(void *p, size_t size);


size_t getsize(void * p);



void		quit(char *s, int errornum);
void		printing(t_shell *data);


char	**test(char **tokens, size_t size, size_t tkns_len);
void	ft_free(char **tokens, size_t tkns_len);


#endif
