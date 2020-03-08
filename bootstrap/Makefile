##
## EPITECH PROJECT, 2020
## cpp_rush3_2019
## File description:
## Makefile
##

NAME	=	libmy_malloc.so

SRC		=	src/malloc.c	    \
			src/free.c			\
			src/calloc.c		\
			src/realloc.c		\

CFLAGS	=	-Wall -Werror -Wextra -fPIC -shared

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re