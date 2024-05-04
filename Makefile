#CC= /opt/homebrew/opt/llvm/bin/clang-18
CC= cc

CFLAGS = -Wall -Werror -Wextra

DEBUG = -fsanitize=address

SRC= $(wildcard *.c)

OBJ= $(SRC:.c=.o)

NAME= a.out

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) -g $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -g -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
