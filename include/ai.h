/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#ifndef AI_H_
#define AI_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define BUFFSIZE (500)
#define LIDAR_SEP(c) (c == ':' || c == '\n')
#define CHOSE_DIR(dir) (dir >= 0.0 ? "" : "-")

char **my_str_to_tab(char const *str);
void my_putstr(char const *str);
void free_tab(char **tab);
int size_tab(char **tab);

#endif /* !AI_H_ */
