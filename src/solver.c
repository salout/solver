/*
** EPITECH PROJECT, 2017
** solver.c
** File description:
**
*/

#include "my.h"

char *move_cursor(int *c_x, int *c_y, char **map, char *path)
{
    int x = *c_x;
    int y = *c_y;
    int i = my_strlen(path);
    char direction;

    if (map[y + 1] != NULL && map[y + 1][x] == '*') {
        *c_y = *c_y + 1;
        direction = 'D';
    } else if (map[y][x + 1] == '*') {
        *c_x = *c_x + 1;
        direction = 'R';
    } else if ((x - 1) >= 0 && map[y][x - 1] == '*') {
        *c_x = *c_x - 1;
        direction = 'L';
    } else if ((y - 1) >= 0 && map[y - 1][x] == '*') {
        *c_y = *c_y - 1;
        direction = 'U';
    }
    path[i++] = direction;
    path[i] = '\0';
    return (path);
}

int check_block(char **map, int x, int y)
{
    if (map[y + 1] != NULL && map[y + 1][x] == '*')
        return (0);
    if (map[y][x + 1] != '\0' && map[y][x + 1] == '*')
        return (0);
    if ((y - 1) >= 0 && map[y - 1][x] == '*')
        return (0);
    if ((x - 1) >= 0 && map[y][x - 1] == '*')
        return (0);
    return (1);
}

char **rewind_map(char **map, char **path, int *c_x, int *c_y)
{
    int x = *c_x;
    int y = *c_y;
    int c_path = my_strlen(*path) - 1;

    while (check_block(map, x, y) != 0 && (x != 0 || y != 0)) {
        map[y][x] = 'X';
        if ((*path)[c_path] == 'U')
            y++;
        if ((*path)[c_path] == 'D')
            y--;
        if ((*path)[c_path] == 'R')
            x--;
        if ((*path)[c_path] == 'L')
            x++;
        (*path)[c_path--] = '\0';
    }
    *c_x = x;
    *c_y = y;
    return (map);
}

void disp_map(char **copy_map, char **map)
{
    int i;

    for (int y = 0; copy_map[y]; y++)
        for (int x = 0; copy_map[y][x]; x++)
            if (copy_map[y][x] == 'o')
                map[y][x] = 'o';
    for (i = 0; map[i + 1]; i++)
        printf("%s\n", map[i]);
    printf("%s", map[i]);
}

void solver(char **map, char **copy_map)
{
    int x = 0;
    int y = 0;
    char *path = malloc(sizeof(char) * 999999);

    path[0] = '\0';
    do {
        copy_map[y][x] = 'o';
        if (check_block(copy_map, x, y) == 1 && x == 0 && y == 0) {
            printf("%s\n", "no solution found");
            return ;
        } else if (check_block(copy_map, x, y) == 1)
            copy_map = rewind_map(copy_map, &path, &x, &y);
        path = move_cursor(&x, &y, copy_map, path);
    } while (copy_map[y + 1] != NULL || copy_map[y][x + 1] != '\0');
    free(path);
    copy_map[y][x] = 'o';
    disp_map(copy_map, map);
}
