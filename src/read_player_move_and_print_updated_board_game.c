/*
** EPITECH PROJECT, 2018
** read_player_move
** File description:
** read
*/

#include <unistd.h>
#include <stdlib.h>
#include "stick.h"

void print_updated_game_board(char **tab, int line, int nb_matches)
{
	int deleted = 0;
	int line_len = my_strlen(tab[line]);

	for (int i = line_len + 1; i > 0; i--) {
		if (tab[line][i] == '|' && deleted < nb_matches) {
			tab[line][i] = ' ';
			deleted++;
		}
	}
	for (int i = 0; tab[i] != NULL ; i++) {
		my_putstr(tab[i]);
		my_putstr("\n");
		}
}
