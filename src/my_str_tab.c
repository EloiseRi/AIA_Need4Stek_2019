/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** splits str into words
*/

#include "ai.h"

#include "../include/get_speed_index.h"

char **my_str_to_tab(char const *str)
{
    int i = 0, j = 0, lght = 0, readsize = BUFFSIZE;
    char **tab = malloc(sizeof(char *) * readsize);

    while (str[i]) {
        if (!LIDAR_SEP(str[i]))
            lght++;
        if (!LIDAR_SEP(str[i]) && LIDAR_SEP(str[i + 1])) {
            tab[j] = malloc(sizeof(char) * (lght + 1));
            strncpy(tab[j], (&str[i - lght + 1]), lght);
            tab[j][lght] = '\0';
            lght = 0;
            j++;
        }
        i++;
    }
    tab[j] = NULL;

    return (tab);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
}

int size_tab(char **tab)
{
    int raw = 0;

    while (tab[raw])
        raw++;

    return (raw);
}