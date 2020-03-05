/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm
*/

#include "my_nm.h"

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
            gestion_data(buf);
        } else {
            perror("mmap");
        }
        close(fd);
    }
    else {
        printf("nm: \" a.out \": no file\n");
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