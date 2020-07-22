# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 16:45:12 by acarlett          #+#    #+#              #
#    Updated: 2020/07/22 17:10:33 by acarlett         ###   ########.fr        #
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
			sources/get_next_line.c \
			sources/ft_strchr.c \
			sources/ft_strdup.c \
			sources/ft_strjoin.c \
			sources/ft_strncpy.c \
			sources/ft_strnew.c \
			sources/ft_strlen.c \
			sources/ft_memalloc.c \
			sources/ft_memset.c \
			sources/ft_atoi.c \
			sources/ft_split.c \
			sources/ft_strsplit.c \

INCLUDES =	includes/rainbow.h \

OBJ = $(patsubst %.c,%.o,$(SOURCES))

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	@cc -I /usr/local/include $(SOURCES) -I $(INCLUDES) -o $(NAME) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(INCLUDES)
	@cc -I $(INCLUDES) $< -c -o $@

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
