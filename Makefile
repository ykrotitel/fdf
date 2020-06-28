SOURCES = main.c

all:
	@cc -I /usr/local/include main.c right_down.c -L fdf/rainbow.h -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

main: all
	@./a.out