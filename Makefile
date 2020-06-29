SOURCES =	main.c \
			right.c \
			down.c \
			left.c \
			up.c \
			make_line.c \

all:
	@cc -I /usr/local/include $(SOURCES) -I rainbow.h -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

main: all
	@./a.out