NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = algo.c \
	  check_tetriminos_1.c \
	  check_tetriminos_2.c \
	  lst_utils.c \
	  main.c \
	  normalize_lst.c \
	  parse_input.c \
	  sqr_utils.c \
	  tetriminos_utils_1.c \
	  tetriminos_utils_2.c

OBJ = $(SRC:.c=.o)


.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) -Llibft -lft -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -I libft -o $@ -c $<

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all
