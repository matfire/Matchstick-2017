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

char *put_bars(char *line, int len, int start, int stop)
{
	char *res;

	res = malloc(sizeof(char) * (len + 3));
	res[0] = '*';
	for (int i = 0; i < len + 1; i++) {
		if (i >= start && i <= stop)
			res[i + 1] = '|';
	}
	res[len + 1] = '*';
	res[len + 2] = '\0';
	return (res);
}

char *fill_line(int len)
{
	char *res;

	res = malloc(sizeof(char) * (len + 4));
	for (int i = 0; i < len + 2; i++)
		res[i] = '*';
	res[len + 3] = '\0';
	return (res);
}

char **create_map(int size)
{
	char **result;
	int total_length = 1 + (2 * (size - 1));
	int start = total_length / 2;
	int stop = start;
	result = malloc(sizeof(char *) * (size + 4));
	result[size + 3] = NULL;
	result[0] = fill_line(total_length);
	for (int i = 1; i < size + 1; i++) {
		result[i] = put_bars(result[i], total_length, start, stop);
		start--;
		stop++;
	}
	result[size + 1] = fill_line(total_length);
	for (int i = 0; i < size + 2; i++) {
		my_putstr(result[i]);
		write(1, "\n", 1);
	}
	return (result);
}
