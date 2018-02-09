/*
** EPITECH PROJECT, 2018
** matches_on_board
** File description:
** matches on board
*/

#include <string.h>
#include <criterion/criterion.h>
#include "stick.h"

Test(get_matches, simple_board)
{
	char **board;

	board = create_map(3);
	cr_assert_eq(get_matches(board), 9);
	for (int i = 0; board[i] != NULL; i++)
		free(board[i]);
	free(board);
}

Test(get_matches, medium_board)
{
	char **board;

	board = create_map(10);
	cr_assert_eq(get_matches(board), 100);
	for (int i = 0; board[i] != NULL; i++)
		free(board[i]);
	free(board);
}

Test(get_matches, large_board)
{
	char **board;

	board = create_map(50);
	cr_assert_eq(get_matches(board), 2500);
	for (int i = 0; board[i] != NULL; i++)
		free(board[i]);
	free(board);
}

Test(get_matches, limit_board)
{
	char **board;

	board = create_map(99);
	cr_assert_eq(get_matches(board), 9801);
	for (int i = 0; board[i] != NULL; i++)
		free(board[i]);
	free(board);
}
