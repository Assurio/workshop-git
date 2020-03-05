/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** data
*/

#include "my_nm.h"

Elf64_Xword print_value(Elf64_Sym *sym)
{
    printf("%lx", sym->st_size);
    (void)sym;
    return sym->st_size;
}

char check_type(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    char c;

    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym->st_shndx].sh_flags == SHF_ALLOC)
       c = 'R';
    return c;
}

Elf64_Word print_name(Elf64_Sym *sym)
{
    printf("%x\n", sym->st_name);
    (void)sym;
    return sym->st_name;
}

int gestion_data(void *buf)
{
    Elf64_Ehdr *ehdr;
    ehdr = (Elf64_Ehdr *)buf;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(buf + ehdr->e_shoff);
    int shnum = ehdr->e_shnum;
    const char *str_p = NULL;

    for(int i = 0; i < shnum; i++) {
        if ((shdr[i].sh_type == SHT_SYMTAB) || (shdr[i].sh_type == SHT_DYNSYM)) {
            str_p =(char *) shdr[shdr[i].sh_link].sh_offset;
            Elf64_Sym *sym = (Elf64_Sym *)(buf + shdr[i].sh_offset);
            for (int j = 0; j < (int)(shdr[i].sh_size/shdr[i].sh_entsize); j++) {
                printf("%016lx ", sym->st_value);
                
                printf("%s\n",(char *) ((uintptr_t)buf + (uintptr_t)str_p + sym->st_name));
                sym++;
            }
        }
    }

    return 0;
}