# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouib <adouib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 22:27:37 by adouib            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/04/11 23:52:01 by adouib           ###   ########.fr        #
=======
#    Updated: 2022/04/12 23:43:45 by jchakir          ###   ########.fr        #
>>>>>>> 5e4a3dd72072d366339bf16bf5ac956e828d5b07
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -I./incl/ -Wall -Wextra -Werror -g3 -fsanitize=address 
# -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -rf

COLOUR_BLUE=\033[0;35m

COLOUR_END=\033[0m

SRCS = ./srcs/main.c \
		./srcs/parser/alloc_init.c ./srcs/parser/parser.c  ./srcs/parser/check.c ./srcs/parser/token_recognition.c \
		./srcs/parser/tokenizer.c ./srcs/parser/envinit.c ./srcs/parser/error_quit.c \
		./srcs/utils_functions/utils.c ./srcs/utils_functions/utils2.c ./srcs/utils_functions/utils3.c \
		./srcs/utils_functions/utils4.c ./srcs/utils_functions/lst_utils.c

SOURCE = srcs/source/calloc.c srcs/source/char_genre.c srcs/source/itoa_and_atoi.c \
		srcs/source/linked_lists.c srcs/source/mem_str_comparing.c srcs/source/put_custom_error.c \
		srcs/source/split.c srcs/source/string_proccessing.c


BUILT_CMD = srcs/builtin_commands/builtin_cmd__unset_.c srcs/builtin_commands/builtin_cmd__echo_.c \
			srcs/builtin_commands/builtin_cmd__env_.c srcs/builtin_commands/builtin_cmd__exit_.c \
			srcs/builtin_commands/builtin_cmd__export_.c srcs/builtin_commands/builtin_cmd__pwd_.c \
			srcs/builtin_commands/builtin_cmd__cd_.c srcs/builtin_commands/builtin_cmd__cd_utils.c

CMD_EXEC = srcs/commands_executor/cmds_executor.c srcs/commands_executor/cmds_executor_utils.c \
			srcs/commands_executor/commands_executor.c srcs/commands_executor/exec_builtin_command.c \
			srcs/commands_executor/exec_other_command.c srcs/commands_executor/get_here_doc.c \
			srcs/commands_executor/input_and_output_fds_minner.c srcs/commands_executor/envs_updater.c 

VARS_HANDLER = srcs/vars_handler/quotes_and_forbidden_chars_checker.c \
				srcs/vars_handler/strings_parser_and_vars_handler.c \
				srcs/vars_handler/var_to_value_in_str.c

# ./srcs/execution/executor.c ./srcs/execution/utils.c

OBJS = $(SRCS:%.c=%.o)
O_SOURCE = $(SOURCE:%.c=%.o)
O_BUILT_CMD = $(BUILT_CMD:%.c=%.o)
O_CMD_EXEC = $(CMD_EXEC:%.c=%.o)
O_VAR_HANDLER = $(VARS_HANDLER:%.c=%.o)

NAME = minishell

$(VERBOSE).SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(O_SOURCE) $(O_BUILT_CMD) $(O_CMD_EXEC) $(O_VAR_HANDLER)
	@$(CC) $(OBJS) $(O_SOURCE) $(O_BUILT_CMD) $(O_CMD_EXEC) $(O_VAR_HANDLER) -lreadline -o $(NAME)
	@echo "👉 $(COLOUR_BLUE)COMPILING DONE$(COLOUR_END) 👈"

./srcs/%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(RM) $(OBJS) $(O_SOURCE) $(O_BUILT_CMD) $(O_CMD_EXEC) $(O_VAR_HANDLER)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
