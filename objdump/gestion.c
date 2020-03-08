/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** gestion
*/

#include "my_objdump.h"

void print_hexa(unsigned char* buf, int const size)
{
  int i = -1;

    while (i++ < 16) {
        if (size > i)
	        printf("%02x", buf[i]);
        else
	        printf("  ");
        if (!((i + 1) % 4))
	        printf(" ");
    }
    printf(" ");
}

void print_ascii(unsigned char* buf, int const size)
{
    int i = -1;

    while (i++ < 16) {
        if (size > i)
	        printf("%c", (buf[i] >= ' ' && buf[i] <= '~') ? buf[i] : '.');
        else
	        printf(" ");
    }
    printf("\n");
}