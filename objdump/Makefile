##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## create the binar
##

SRC	=	my_objdump.c	\
		header.c		\
		data.c			\
		gestion.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -g3

NAME	=	../my_objdump

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:		clean fclean re