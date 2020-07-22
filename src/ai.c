/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#include "ai.h"
#include "../include/get_speed_index.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int exec_cmd(char *cmd, char *neg, char *value)
{
    char *lidstr = NULL;
    size_t size = 0;

    write(1, cmd, strlen(cmd));
    write(1, neg, strlen(neg));
    write(1, value, strlen(value));
    getline(&lidstr, &size, stdin);

    return (0);
}

int speeding(float front)
{
    char *speed[6] = {"0.1\n", "0.2\n", "0.4\n", "0.5\n", "0.7\n", "0.9\n"};

    exec_cmd("CAR_FORWARD:", "", speed[get_speed_index(front)]);

    return (0);
}

int steering(float left, float right, int front)
{
    float dir = left - right;
    if (front <= 300)
        return (exec_cmd("WHEELS_DIR:", CHOSE_DIR(dir), "0.5\n"));
    if (front <= 400)
        return(exec_cmd("WHEELS_DIR:", CHOSE_DIR(dir), "0.4\n"));
    if (front <= 600)
        return(exec_cmd("WHEELS_DIR:", CHOSE_DIR(dir), "0.2\n"));
    if (front <= 950)
        return(exec_cmd("WHEELS_DIR:", CHOSE_DIR(dir), "0.1\n"));
    if (front <= 1500)
        return(exec_cmd("WHEELS_DIR:", CHOSE_DIR(dir), "0.05\n"));
    return (exec_cmd("WHEELS_DIR:", CHOSE_DIR(dir), "0\n"));
}

int move_car(char **lidar)
{
    float front, left, right;

    if (lidar[17] == NULL)
        return (1);

    front = get_moy(lidar, 15, 24);
    left = get_moy(lidar, 4, 14);
    right = get_moy(lidar, 25, 35);

    if (strcmp(lidar[35], "Track Cleared") == 0)
        return (0);

    speeding(front);
    steering(left, right, front);

    return (1);
}

int main(void)
{
    char *lidstr = NULL;
    size_t size = 0;
    char **lidar;

    my_putstr("START_SIMULATION\n");
    while (true) {
        my_putstr("GET_INFO_LIDAR\n");
        if (getline(&lidstr, &size, stdin) == -1) break;
        lidar = my_str_to_tab(lidstr);
        if (size_tab(lidar) != 36)
            if (strcmp(lidar[3], "Track Cleared") == 0) break;

        if (!move_car(lidar)) break;
        free_tab(lidar);
    }
    write(1, "CAR_FORWARD:0\n", 15);
    write(1, "STOP_SIMULATION\n", 17);
    return (0);
}