/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm
*/

#include "my_nm.h"

int nb_check(void *buf, char *file)
{
    Elf64_Ehdr ehdr;
    FILE* fd = fopen(file, "r");

    fread(&ehdr, 1, sizeof(ehdr), fd);
    if (ehdr.e_ident[4] == ELFCLASS32) {
        //gestion_data2(buf);
    }
    else {
        gestion_data1(buf);
    }
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
        if (buf != NULL) {
            nb_check(buf, file);
        } else {
            perror("mmap");
        }
        close(fd);
    }
    else {
        fprintf(stderr, "nm: '%s': No such file\n", file);
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