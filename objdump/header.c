/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** header
*/

#include "my_objdump.h"

int check_type(Elf64_Ehdr *elf)
{
    if (elf->e_type == ET_REL)
        return HAS_SYMS | HAS_RELOC;
    if (elf->e_type == ET_EXEC)
        return D_PAGED | HAS_SYMS | EXEC_P;
    if (elf->e_type == ET_DYN)
        return D_PAGED | DYNAMIC | HAS_SYMS;
    return 0;
}

char *check_flag(Elf64_Ehdr *elf)
{
    if (elf->e_type == 1)
        return "HAS_RELOC, HAS_SYMS";
    if (elf->e_type == 2)
        return "EXEC_P, HAS_SYMS, D_PAGED";
    if (elf->e_type == 3)
        return "HAS_SYMS, DYNAMIC, D_PAGED";
    return NULL;
}

void gestion_header(char *file, Elf64_Ehdr *elf)
{
        printf("%s:\tfile format elf64-x86-64\n", file);
        printf("architecture: %s, flags 0x%08x:\n%s\n",
        elf->e_machine == EM_X86_64 ? "i386:x86-64" : "i386", check_type(elf),
        check_flag(elf));
        printf("start address 0x%016lx\n", elf->e_entry);
}