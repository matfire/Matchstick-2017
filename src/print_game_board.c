/*
** EPITECH PROJECT, 2018
** print_game_board
** File description:
** print game board
*/

#include <stdlib.h>
#include <unistd.h>

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

void print_game_board(void)
{
	char **tab;

	tab = malloc(sizeof(char*) * (7));
	tab[6] = NULL;
	tab[0] = "*********\n\0";
	tab[1] = "*   |   *\n\0";
	tab[2] = "*  |||  *\n\0";
	tab[3] = "* ||||| *\n\0";
	tab[4] = "*|||||||*\n\0";
	tab[5] = "*********\n\0";
	for (int i = 0; i < 6; i++)
		my_putstr(tab[i]);
}
