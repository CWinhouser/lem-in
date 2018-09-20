# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/31 11:26:55 by ktwomey           #+#    #+#              #
#    Updated: 2018/09/19 12:17:17 by ktwomey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
cc = gcc
CFLAGS = -Wall -Werror -Wextra -c 
FUNCS = ft_atoi \
ft_bzero \
ft_intlen \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_itoa \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \
ft_putchar \
ft_putchar_fd \
ft_putendl \
ft_putendl_fd \
ft_putnbr \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_strcat \
ft_strchr \
ft_strclr \
ft_strcmp \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_striter \
ft_striteri \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnstr \
ft_strrchr \
ft_strstr \
ft_strsub \
ft_tolower \
ft_toupper \
ft_isspace \
ft_strsplit \
ft_strjoin \
ft_strtrim \
ft_strnjoin \

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))
all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) $(SRCC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)
clean:
	/bin/rm -f $(SRCO)
fclean: clean 
	/bin/rm -f $(NAME)
re: fclean all
