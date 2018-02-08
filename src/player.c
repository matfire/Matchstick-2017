/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#include "stick.h"
#include "get_next_line.h"

int check_line(char **map, char *line)
{
	int i = 0;

	for (; map[i] != NULL; i++);
	if (my_getnbr(line) <= 0 || my_getnbr(line) > i) {
		my_putstr("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}

int has_enough_matches(char **board, int line, int matches)
{
	int matches_on_line = 0;

	for (int i = 0; board[line][i] != '\0'; i++) {
		if (board[line][i] == '|')
			matches_on_line++;
	}
	if (matches > matches_on_line) {
		my_putstr("Error: not enough matches on this line\n");
		return (1);
	}
	return (0);
}

int check_matches(char **map, int matches_nb, char *matches, int line)
{
	if (is_number(matches)) {
		my_putstr("Error: input must be a positive number\n");
		return (1);
	}
	if (my_getnbr(matches) == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (1);
	}
	if (my_getnbr(matches) > matches_nb) {
		my_putstr("Error: you cannot remove more than ");
		my_putstr(matches);
		my_putstr(" matches per turn\n");
		return (1);
	}
	if (has_enough_matches(map, line, my_getnbr(matches)))
		return (1);
	return (0);
}

void player_turn(char **map, int matches_nb)
{
	char *line;
	char *match;

	my_putstr("Line: ");
	line = get_next_line(0);
	if (check_line(map, line)) {
		free(line);
		player_turn(map, matches_nb);
	}
	my_putstr("Matches: ");
	match = get_next_line(0);
	while (check_matches(map, matches_nb, match, my_getnbr(line))) {
		free(match);
		my_putstr("Matches: ");
		match = get_next_line(0);
	}
	print_updated_game_board(map, my_getnbr(line), my_getnbr(match));
}
