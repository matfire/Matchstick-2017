/*
** EPITECH PROJECT, 2018
** ai
** File description:
** ai
*/

#include "stick.h"
#include <stdio.h>

int generate_line(char **board)
{
	int len_board = board_len(board);
	int res = (int)random() % (len_board - 1);

	while (!(res >= 1 && res <= len_board - 1 ))
		res = (int)random() % (len_board - 1);
	while (get_matches_on_line(board, res) == 0)
		res = (int)random() % (len_board - 1);
	return (res);
}

int generate_matches(char **board, int line)
{
	int matches_on_line = get_matches_on_line(board, line);
	int res = 0;

	if (matches_on_line == 0)
		return (0);
	res = (int)random() % matches_on_line;
	if (res == 1 || matches_on_line == 1)
		return (1);
	while (!(res >= 1 && res <= matches_on_line))
		res = (int)random() % matches_on_line;
	return (res);
}

int line_has_matches(char **board, int line, int matches)
{
	int matches_on_line = 0;

	for (int i = 0; board[line][i] != '\0'; i++) {
		if (board[line][i] == '|')
			matches_on_line++;
	}
	if (matches > matches_on_line || matches == 0)
		return (1);
	return (0);
}

int board_has_no_more_matches(char **board)
{
	for (int i = 0; board[i] != NULL; i++) {
		if (line_has_matches(board, i, 1))
			return (0);
		printf("there are still matches on line %d\n", i);
	}
	return (1);
}

void ai_turn(char **board)
{
	int line = generate_line(board);
	int matches_to_be_removed = 0;

	if (board_has_no_more_matches(board))
		return;
	if ((matches_to_be_removed = generate_matches(board, line)) == 0) {
		print_ia_moves(line, 1);
		print_updated_game_board(board, line, 1);
		return;
		}
	if (line_has_matches(board, line, matches_to_be_removed))
		ai_turn(board);
	print_ia_moves(line, matches_to_be_removed);
	print_updated_game_board(board, line, matches_to_be_removed);
}
