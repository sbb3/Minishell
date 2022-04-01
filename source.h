
#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

#define INITIAL 200

extern char **environ;

enum e_id
{
	LESS,	   // <
	HEREDOC, // <<
	GREATER, // >
	APPEND,  // >>
	INFILE,
	OUTFILE,
	OUTFILE_APPEND,
	DELIMITER,
	COMMAND,
	ARGS, // text or 'text' or '$text'
	DQUOTES, // ""
	SQUOTES, // ''
	USD, // $text or txt1$usd
	EXITSTATUS,
	DQUOTES_USD,
	SQUOTES_USD, //
	OTHER,
};

enum e_types
{
	LEFT_REDIREC = '<',
	RIGHT_REDIREC = '>',
	DOUBLEQUOTE = '"',
	SINGLEQUOTE = '\'',
};

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
} t_env;


typedef struct s_component
{
	char *content;
	int type;
	struct s_component *next;
} t_component;

typedef struct s_shell
{
	t_component **separator;
	t_env *envp;
	char **envs;
	int parts_count;
	// int tks_count[1000];
	int exit_status;
	int *tkns_recognition;
	int start;
	char **tokens;
	int tokens_len;
	int infile_fd;
	int outfile_fd;
} t_shell;


typedef struct s_pipex
{
	int infile_fd;
	int outfile_fd;
	int pipefd[2];
	pid_t pid;
	char *cmd1_fullpath;
	char *cmd2_fullpath;
	char **cmd1_args;
	char **cmd2_args;
	char *path;
	char *paths;

} t_pipex;


#endif
