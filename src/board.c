/*
** EPITECH PROJECT, 2018
** board
** File description:
** board
*/

#include "stick.h"

char *fill_borders(char *line, int len)
{
	char *res;

	res = malloc(sizeof(char) * (len + 3));
	res[0] = '*';
	for (int i = 1; i < len + 1; i++)
		res[i] = ' ';
	res[len + 1] = '*';
	res[len + 2] = '\0';
	return (res);
}

void put_bars(char *line, int index)
{

}

char *fill_line(int len)
{
	char *res;

	res = malloc(sizeof(char) * (len + 1));
	for (int i = 0; 
}

char **create_map(int size)
{
	char **result;
	int total_length = 1 + (2 * (size - 1));
	result = malloc(sizeof(char *) * (size + 4));
	result[size + 2] = NULL;
	result[0] = fill_line(total_length);
	for (int i = 1; i < size + 1; i++) {
		result[i] = fill_borders(result[i], total_length);
	}
	result[size + 2] = fill_line(total_length);
	for (int i = 0; result[i] != NULL; i++) {
		my_putstr(result[i]);
		write(1, "\n", 1);
	}
	return (result);
}
