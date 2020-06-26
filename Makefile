SOURCES = main.c

all:
	@cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

main: all
	@./a.out