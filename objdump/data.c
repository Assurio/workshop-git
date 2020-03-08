/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** data
*/

#include "my_objdump.h"


void print_data(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, int const i, int const j)
{
  printf(" %04x ", (int)(shdr[i].sh_addr + j - shdr[i].sh_offset));
  print_hexa((unsigned char *)ehdr + j,
	     shdr[i].sh_offset + shdr[i].sh_size - j);
  print_ascii((unsigned char *)ehdr + j,
	      shdr[i].sh_offset + shdr[i].sh_size - j);
}

int section_check(int i, Elf64_Shdr *shdr)
{
    return (shdr[i].sh_name && shdr[i].sh_type != SHT_NOBITS &&
    shdr->sh_flags != SHF_INFO_LINK && shdr[i].sh_size > 0 &&
    (shdr[i].sh_addr || (!shdr[i].sh_addr && shdr[i].sh_type != SHT_STRTAB &&
    shdr[i].sh_type != SHT_REL && shdr[i].sh_type != SHT_RELA &&
    shdr[i].sh_type != SHT_SYMTAB)));
}

int gestion_data(Elf64_Ehdr *ehdr, void *buf)
{
    Elf64_Shdr *shdr = buf + ehdr->e_shoff;
    Elf64_Shdr *shdr2 = &shdr[ehdr->e_shstrndx];
    int shnum = ehdr->e_shnum;
    char *str = buf + shdr2->sh_offset;
    unsigned int j;

    for (int i = 0; i < shnum ;i++) {
        if (section_check(i, shdr)) {
            printf("Contents of section %s:\n", str + shdr[i].sh_name);
        }
        j = shdr[i].sh_offset;
        while (j < shdr[i].sh_offset + shdr[i].sh_size) {
            print_data(ehdr, shdr, i, j);
            j += 16;
        }
    }
    return 0;
}