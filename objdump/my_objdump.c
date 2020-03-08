/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#include "my_objdump.h"

int gestion(char *file, int fd, void *buf)
{
    Elf64_Ehdr *ehdr;
        if (buf != NULL) {
                ehdr = buf;
                if (ehdr->e_ident[0] == 0x7F && ehdr->e_ident[1] == 'E' &&
                ehdr->e_ident[2] == 'L' && ehdr->e_ident[3] == 'F') {
                    gestion_header(file, ehdr);
                    gestion_data(ehdr, buf);
                } else {
                    fprintf(stderr, "objdump: %s: file format not recognized\n", file);
                    exit (84);
                }
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
        fprintf(stderr, "objdump: '%s': No such file\n", file);
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