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

main: all
	@./a.out test_maps/10-70.fdf | cat -e