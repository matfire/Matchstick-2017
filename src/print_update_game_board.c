/*
** EPITECH PROJECT, 2018
** print_updated_game_board
** File description:
** update
*/

#include <unistd.h>
#include <stdlib.h>
/*
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
*/

char *my_strcpy(char *str)
{
	int i = 0;
	char *dest;

	dest = malloc(sizeof(char) * (my_strlen(str) + 2));
	while (str[i] != '\0') {
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void print_updated_game_board(int line, int nb_matches)
{
	char **tab;
	int deleted = 0;
	int line_len;

	tab = malloc(sizeof(char*) * 7);
	tab[6] = NULL;
	tab[0] = my_strcpy("*********\n\0");
	tab[1] = my_strcpy("*   |   *\n\0");
	tab[2] = my_strcpy("*  |||  *\n\0");
	tab[3] = my_strcpy("* ||||| *\n\0");
	tab[4] = my_strcpy("*|||||||*\n\0");
	tab[5] = my_strcpy("*********\n\0");
	line_len = my_strlen(tab[line]);
	for (int i = line_len + 1; i > 0; i--) {
		if (tab[line][i] == '|' && deleted < nb_matches) {
			tab[line][i] = ' ';
			deleted++;
		}
	}
	for (int i = 0; i < 6; i++) {
		my_putstr(tab[i]);
		free(tab[i]);
		}
	free(tab);
}
