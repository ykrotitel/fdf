# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 16:45:12 by acarlett          #+#    #+#              #
#    Updated: 2020/07/13 16:45:19 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	main.c \
			right.c \
			down.c \
			left.c \
			up.c \
			make_line.c \
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
			libft/help.c \

INCLUDES =	rainbow.h \

all:
	@cc -I /usr/local/include $(SOURCES) -I $(INCLUDES) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

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

clean:
	@rm -rf a.out

re: clean all