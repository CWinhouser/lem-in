# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 10:59:39 by ktwomey           #+#    #+#              #
#    Updated: 2018/09/27 12:04:36 by ktwomey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCES = srcs/main.c srcs/read.c srcs/algo.c srcs/algoext.c srcs/error.c srcs/print.c
INCLUDES = includes/libft/libft.a includes/get_next_line/get_next_line.c

$(NAME):
	make -C includes/libft
	gcc -o $(NAME) -ggdb3 $(SOURCES) $(INCLUDES)

all: $(NAME)

clean:
	make clean -C includes/libft
	rm -f $(NAME)

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean all
