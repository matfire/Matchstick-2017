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
int my_strlen(char *str);
int is_number(char *str);
int check(char **map);
int check_values(char **av);
char **create_map(int size);
char *put_bars(int len, int start, int stop);
void print_board(char **map);
void my_putstr(char *str);
void player_turn(char **map, int matches_nb);
void print_updated_game_board(char **tab, int line, int nb_matches);
#endif
