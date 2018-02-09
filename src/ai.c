/*
** EPITECH PROJECT, 2018
** ai
** File description:
** ai
*/

#include "stick.h"

int generate_line(char **board)
{
	int len_board = board_len(board);
	int res = (int)random() % (len_board - 1);

	while (!(res >= 1 && res <= len_board - 1 ))
		res = (int)random() % (len_board - 1);
	if (get_matches_on_line(board, res) == 0)
		generate_line(board);
	printf("Line : %d\n", res);
	return (res);
}

int generate_matches(char **board, int max_matches, int line)
{
	int res = (int)random() % max_matches;

	while (!(res >= 1 && res <= get_matches_on_line(board, line)) || res == 1)
		res = (int)random() % get_matches_on_line(board, line);
	return (res);
}

void ai_turn(char **board, int max_matches)
{
	int line = generate_line(board);
	int matches_to_be_removed = generate_matches(board, max_matches, line);

	print_ia_moves(line, matches_to_be_removed);
	print_updated_game_board(board, line, matches_to_be_removed);
}
