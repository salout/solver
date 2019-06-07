/*
** EPITECH PROJECT, 2017
** my_str_to_array.c
** File description:
** my_str_to_array.c
*/

#include "my.h"

int my_strlen(char *str)
{
    int res;

    for (res = 0; str[res]; res++);
    return (res);
}

int count_space(char const *str, char key)
{
    int a = 0;
    int i = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == key && a == 0) {
            a = 1;
            i++;
        } else if (str[x] != key && a == 1)
            a = 0;
    }
    return (i + 1);
}

int count_size(char *str, int x, char key)
{
    int res;

    for (res = 0; str[x] != key && str[x] != '\0'; x++)
        res++;
    return (res + 1);
}

char **my_str_to_array(char *str, char key)
{
    int y = 0;
    int a = 0;
    char **temp = malloc(sizeof(char * ) * count_space(str, key));

    temp[y] = malloc(sizeof(char *) * count_size(str, 0, key));
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == key && a == 0)
            a = 0;
        else if (str[x] != key)
            temp[y][a++] = str[x];
        else if (str[x + 1] != '\0'){
            temp[y][a] = '\0';
            temp[++y] = malloc(sizeof(char) * count_size(str, x + 1, key));
            a = 0;
        }
    }
    temp[y][a] = '\0';
    temp[++y] = NULL;
    return (temp);
}
