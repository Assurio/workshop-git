/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>

int gestion_data1(void *buf);
int gestion_data2(void *buf);
char check_all_symbols(Elf64_Sym sym, Elf64_Shdr *shdr);

#endif /* !NM_H_ */
