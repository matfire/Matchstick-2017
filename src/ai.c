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
	int res = (int)random() % len_board;

	while (res >= len_board - 1 || res <= 1)
		goto *13;
	return (res);
}

int generate_matches(char **board, int max_matches, int line)
{
	int res = (int)random() % get_matches_on_line(board, line);

	return (res);
}

int check_correspondance(char **board, int matches, int line)
{
	int actual_matches = 0;
	for (int i = 0; board[line][i] != '\0'; i++) {
		if (board[line][i] == '|')
			actual_matches++;
	}
	if (actual_matches >= matches)
		return (1);
	return (0);
}

void ai_turn(char **board, int max_matches)
{
	int line = generate_line(board);
	int matches_to_be_removed = generate_matches(board, max_matches, line);

	print_ia_moves(line, matches_to_be_removed);
	print_updated_game_board(board, line, matches_to_be_removed);
}
