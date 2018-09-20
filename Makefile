# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 10:59:39 by ktwomey           #+#    #+#              #
#    Updated: 2018/09/20 12:37:57 by ktwomey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCES = srcs/main.c srcs/read.c srcs/algo.c
INCLUDES = includes/libft/libft.a includes/get_next_line/get_next_line.c

$(NAME):
	make -C includes/libft
	gcc -o $(NAME) -Wall -Werror -Wextra -ggdb3 $(SOURCES) $(INCLUDES)

all: $(NAME)

clean:
	make clean -C includes/libft
	rm -f $(NAME)

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean all
