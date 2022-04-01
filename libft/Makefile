# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 10:32:40 by jchakir           #+#    #+#              #
#    Updated: 2022/02/10 18:35:32 by jchakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
FUNCS = atoi.c bzero.c calloc.c isalnum.c isalpha.c isascii.c isdigit.c \
		isprint.c itoa.c memchr.c memcmp.c memcpy.c memmove.c memset.c \
		putchar_fd.c putendl_fd.c putnbr_fd.c putstr_fd.c split.c strchr.c \
		strdup.c striteri.c strjoin.c strlcat.c strlcpy.c strlen.c strmapi.c \
		strncmp.c strnstr.c strrchr.c strtrim.c substr.c tolower.c toupper.c

BONUS = lstadd_back.c lstadd_front.c lstclear.c lstdelone.c lstiter.c \
		lstlast.c lstmap.c lstnew.c lstsize.c

OBJ = $(FUNCS:.c=.o)
BOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -rf  $(NAME)

clean:
	rm -rf $(OBJ) $(BOBJ)

re: fclean all

bonus: all $(BOBJ)
	ar rcs $(NAME) $(BOBJ)
