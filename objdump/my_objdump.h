/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include "flags.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>

void gestion_header(char *file, Elf64_Ehdr *elf);
int gestion_data(char *file, Elf64_Ehdr *elf);

#endif /* !OBJDUMP_H_ */
