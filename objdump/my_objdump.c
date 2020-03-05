/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#include "my_objdump.h"

int gestion(char *file, int fd, void *buf)
{
    Elf64_Ehdr *elf;
        if (buf != NULL) {
                elf = buf;
                if (elf->e_ident[0] == 0x7F && elf->e_ident[1] == 'E' &&
                elf->e_ident[2] == 'L' && elf->e_ident[3] == 'F') {
                    gestion_header(file, elf);
                    // gestion_data(file);
                } else
                    exit (84);
        } else
            perror("mmap");
        close(fd);
    return 0;
}

int elf(char *file)
{
    int fd;
    void *buf;
    struct stat s;
    fd = open (file, O_RDONLY);
    if (fd != -1) {
        fstat(fd, &s);
        buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        gestion(file, fd, buf);
    }
    else {
        printf("objdump: \'a.out\': No such file\n");
        exit (84);
    }
    return 0;
}

int main(int ac, char **av)
{
    char *file;
    if (ac == 1) {
        file = malloc(sizeof(char) * 6);
        file = "a.out";
    }
    else {
        file = malloc(sizeof(char) * strlen(av[1]) + 1);
        file = av[1];
    }
    elf(file);

    return 0;
}