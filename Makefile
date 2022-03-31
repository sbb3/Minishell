# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouib <adouib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 22:27:37 by adouib            #+#    #+#              #
#    Updated: 2022/03/31 13:57:56 by adouib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -I./incl/ -Wall -Wextra -Werror
# -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -rf

COLOUR_BLUE=\033[0;35m

COLOUR_END=\033[0m

SRCS = ./srcs/main.c \
		./srcs/builtins/builtins_cmds.c \
		./srcs/error/error.c \
		./srcs/parser/alloc.c ./srcs/parser/init.c  ./srcs/parser/check.c ./srcs/parser/token_recognition.c ./srcs/parser/tokenizer.c ./srcs/parser/envinit.c\
		./srcs/utils_functions/utils.c ./srcs/utils_functions/utils2.c ./srcs/utils_functions/utils3.c ./srcs/utils_functions/utils4.c ./srcs/utils_functions/lst_utils.c\

# ./srcs/execution/executor.c ./srcs/execution/utils.c

OBJS = $(SRCS:%.c=%.o)

NAME = minishell

$(VERBOSE).SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)
	@echo "👉 $(COLOUR_BLUE)COMPILING DONE$(COLOUR_END) 👈"

./srcs/%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
