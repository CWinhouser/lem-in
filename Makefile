# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 10:59:39 by ktwomey           #+#    #+#              #
#    Updated: 2018/09/29 09:35:28 by ktwomey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCES = srcs/main.c srcs/read.c srcs/algo.c srcs/algoext.c srcs/error.c srcs/print.c srcs/clean.c
INCLUDES = includes/libft/libft.a includes/get_next_line/get_next_line.c

$(NAME):
	make -C includes/libft
	gcc -o $(NAME) -Wall -Werror -Wextra -ggdb3 $(SOURCES) $(INCLUDES)

all: $(NAME)

clean:
	make clean -C includes/libft

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean all
