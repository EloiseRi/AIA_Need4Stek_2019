/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** erghb
*/

#include "ai.h"

void my_putstr(char const *str)
{
    if (str == NULL) {
        my_putstr("(null)");
    }

    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
