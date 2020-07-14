# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 19:11:45 by acarlett          #+#    #+#              #
#    Updated: 2020/07/14 19:14:27 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_atoi.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strsplit.c \

O =		ft_atoi.o \
		ft_memalloc.o \
		ft_memset.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strncpy.o \
		ft_strnew.o \
		ft_strsplit.o \

all: $(NAME)

$(NAME): $(O)
		@ar rc $(NAME) $(O)
		@ranlib $(NAME)

$(O): %.o: %.c
		@gcc -Wall -Wextra -Werror -c $^

clean:
		@/bin/rm -f $(O)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all