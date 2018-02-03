/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get next line
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer_read[READ_SIZE];
	static int i;
	static int index;
	int j = 0;
	char *res;

	res = malloc(sizeof(char) * (READ_SIZE + 1));
	index = (i == 0 ? read(fd, buffer_read, READ_SIZE) : index);
	while (i <= index && j <= READ_SIZE) {
		if (j == READ_SIZE)
			return (res);
		if (buffer_read[i] == '\n') {
			i++;
			res[j] = '\0';
			return (res);
		}
		index = (i >= index ? read(fd, buffer_read, READ_SIZE) : index);
		i = (i >= index ? 0 : i);
		res[j++] = buffer_read[i++];
	}
	return (NULL);
}
