/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils
*/

#include "stick.h"

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int board_len(char **board)
{
	int i = 0;

	for (; board[i] != NULL; i++);
	return (i);
}

int get_matches(char **board)
{
	int matches = 0;

	for (int i = 0; board[i] != NULL; i++) {
		for (int y = 0; board[i][y] != '\0'; y++) {
			if (board[i][y] == '|')
				matches++;
		}
	}
	return (matches);
}

int get_matches_on_line(char **board, int line)
{
	int matches;

	for (int i = 0; board[line][i] != '\0'; i++) {
		if (board[line][i] == '|')
			matches++;
	}
	return (matches);
}
