/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** load
*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    void *handle = dlopen(av[1], RTLD_LAZY);
    void *(*my)(size_t);

    if (!handle) {
        printf("can't open lib\n");
        exit(1);
    }
    dlerror();
    my = dlsym(handle, "about");
    char **test = (*my)(sizeof(char *) * (2));
    dlclose(handle);
}