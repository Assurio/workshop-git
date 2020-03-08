/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** symbol
*/

#include "my_nm.h"

char check1(char c, Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        c = 'u';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        c = 'W';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'w';
        }
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        c = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'v';
        }
    if (sym.st_shndx == SHN_UNDEF)
        c = 'U';
    if (sym.st_shndx == SHN_ABS)
        c = 'A';
    if (sym.st_shndx == SHN_COMMON)
        c = 'C';
    return c;
}

char check_all_symbols(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c = 'x';
    c = check1(c, sym);
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'B';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
        c = 'R';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'D';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        c = 'T';
    if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        c = 'D';
    if (c == 'x')
        c = '?';
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}