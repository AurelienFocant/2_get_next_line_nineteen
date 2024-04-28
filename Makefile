CC= /opt/homebrew/opt/llvm/bin/clang-18
#CC= cc

CFLAGS = -Wall -Werror -Wextra

DEBUG = -fsanitize=address -g

SRC= $(wildcard *.c)

OBJ= $(SRC:.c=.o)

NAME= a.out

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DEBUG) $^ libft.a -o $@

%.o: %.c
	$(CC) $(DEBUG) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
