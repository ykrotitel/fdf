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

INCLUDES =	rainbow.h \

all:
	@cc -I /usr/local/include $(SOURCES) -I $(INCLUDES) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

main: all
	@./a.out test_maps/10-2.fdf | cat -e