/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:31:55 by adouib            #+#    #+#             */
/*   Updated: 2022/04/07 01:06:01 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

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
};

enum e_types
{
	LREDIR = '<',
	RREDIR = '>',
	DOUBLEQUOTE = '"',
	SINGLEQUOTE = '\'',
	PIPE = '|',
};

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
	int					*pids;
	int					*pipefds;

}	t_shell;

#endif
