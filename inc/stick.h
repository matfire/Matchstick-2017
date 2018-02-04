/*
** EPITECH PROJECT, 2018
** stick
** File description:
** stick
*/

#ifndef MY_STICK

#define MY_STICK
#include <stdlib.h>
#include <unistd.h>

int my_getnbr(char *str);
char **create_map(int size);
char *put_bars(char *line, int len, int start, int stop);
void print_board(char **map);

#endif
