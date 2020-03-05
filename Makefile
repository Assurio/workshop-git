##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

all:		nm objdump

nm:
	make -C nm
objdump:
	make -C objdump

clean:
		make clean -C nm
		make clean -C objdump

fclean:		clean
		make fclean -C nm
		make fclean -C objdump

re:		fclean all

.PHONY:		make clean fclean re nm objdump
