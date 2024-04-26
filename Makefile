CFLAGS = -Wall -Werror -Wextra
SRC= $(wildcard *.c)

OBJ= $(SRC:.c=.o)

NAME= a.out

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -g $^ -o $@

%.o: %.c
	cc $(CFLAGS) -g -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
