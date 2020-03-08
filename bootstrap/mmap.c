/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** mmap
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main (int ac, char **av)
{
    int fd;
    void *buf;
    struct stat s;
    fd = open (av[1], O_RDONLY);
    if (fd != -1) {
        fstat(fd, &s);
        buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
            if (buf != NULL) {
                printf("mmap (%s):%08x %s\n", av[1], buf, buf);
                munmap(buf, s.st_size);
            } else {
                perror("mmap");
            }
        close(fd);
    }
}