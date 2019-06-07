/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main.c
*/

#include "my.h"

char *copy_temp(char *map_temp, char *temp, int size)
{
    int i;

    for (i = 0; i != size; i++)
        map_temp[i] = temp[i];
    map_temp[i] = '\0';
    return (map_temp);
}

int setup(int fd)
{
    char *temp = malloc(sizeof(char) * 1000);
    char *map_temp;
    char **map;
    char **copy_map;
    int size = read(fd, temp, 1000);

    map_temp = malloc(sizeof(char) * size + 1);
    map_temp = copy_temp(map_temp, temp, size);
    free(temp);
    map = my_str_to_array(map_temp, '\n');
    copy_map = my_str_to_array(map_temp, '\n');
    free(map_temp);
    solver(map, copy_map);
    return (0);
}

int main(int ac, char **av)
{
    int fd;

    if (ac != 2)
        return (84);
    else if ((fd = open(av[1], O_RDONLY)) == -1)
        return (84);
    else
        return (setup(fd));
}
