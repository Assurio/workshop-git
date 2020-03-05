##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

SRC	=	my_nm.c		\
		data.c		\
		symbol.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -g3

NAME	=	../my_nm

all:		build

build:		$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f *~
		rm -f $(NAME)
		rm -f vgcore.*

fclean:		clean
		rm -f $(OBJ)
		rm -f *~
		rm -f $(NAME)
		rm -f vgcore.*

re:		fclean all

.PHONY:		make clean fclean re
