CC = clang
NAME = main.c
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -o out
LFLAGS = -ILibmx/inc Libmx/libmx.a

all:
	@$(CC) $(CFLAGS) $(LFLAGS) $(NAME)


uninstall:
	@rm -f out
#alias go='cd Libmx && make && cd .. && make && ./out && rm out'
