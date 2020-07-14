# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 16:45:12 by acarlett          #+#    #+#              #
#    Updated: 2020/07/14 19:19:44 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	sources/main.c \
			sources/right.c \
			sources/down.c \
			sources/left.c \
			sources/up.c \
			sources/make_line.c \
			sources/help.c \
			sources/spin.c \
			sources/key_press.c \
			sources/take_param.c \
			sources/all_line.c \
			sources/conditions.c \
			libft/get_next_line.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_strjoin.c \
			libft/ft_strncpy.c \
			libft/ft_strnew.c \
			libft/ft_strlen.c \
			libft/ft_memalloc.c \
			libft/ft_memset.c \
			libft/ft_atoi.c \
			libft/ft_strsplit.c \

INCLUDES =	includes/rainbow.h \

OBJ = $(patsubst %.c,%.o,$(SOURCES))

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) clean
	@cc -Wall -Wextra -Werror  -I /usr/local/include $(SOURCES) -I $(INCLUDES) -o $(NAME) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@cc -Wall -Werror -Wextra -I $(INCLUDES) $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf 

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re

main1: all
	@./a.out test_maps/42.fdf

main2: all
	@./a.out test_maps/10-70.fdf

main3: all
	@./a.out test_maps/pylone.fdf

main4: all
	@./a.out test_maps/pentenegpos.fdf

main5: all
	@./a.out test_maps/t1.fdf

main6: all
	@./a.out test_maps/mars.fdf

main7: all
	@./a.out test_maps/pyramide.fdf

main8: all
	@./a.out test_maps/50-4.fdf

main9: all
	@./a.out test_maps/pyra.fdf

fuck: all
	@./a.out test_maps/fuuuuck.fdf