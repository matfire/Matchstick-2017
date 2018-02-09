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
#include <time.h>

int my_getnbr(char *str);
int my_strlen(char *str);
int is_number(char *str);
int check(char **map);
int check_values(char **av);
int board_len(char **board);
int get_matches(char **board);
int get_matches_on_line(char **board, int line);
char **create_map(int size);
char *put_bars(int len, int start, int stop);
void print_board(char **map);
void my_putstr(char *str);
void print_ia_moves(int line, int matches);
void ai_turn(char **board, int max_matches);
void player_turn(char **map, int matches_nb);
int my_put_nbr(int nb);
void print_updated_game_board(char **tab, int line, int nb_matches);

#endif
