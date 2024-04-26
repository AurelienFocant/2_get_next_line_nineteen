CFLAGS = -Wall -Werror -Wextra
SRC= $(wildcard *.c)

OBJ= $(SRC:.c=.o)

NAME= a.out

all: $(NAME)

$(NAME): $(OBJ)
	cc $() -g $^ libft.a -o $@

%.o: %.c
	cc $() -g -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
