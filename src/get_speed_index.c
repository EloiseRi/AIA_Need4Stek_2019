/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** get_speed_index
*/

#include "../include/get_speed_index.h"
#include <stdio.h>
#include <stdlib.h>

int get_speed_index(int front)
{
    if (front > 2000)
        return (5);
    if (front > 1500)
        return (4);
    if (front > 1000)
        return (3);
    if (front > 600)
        return (2);
    if (front > 400)
        return (1);
    return (0);
}

float get_moy(char **lidar, int x, int y)
{
    float moy = 0;

    for (int i = x; i != y; i++)
        moy += atof(lidar[i]);
    moy /= y - x;

    return (moy);
}