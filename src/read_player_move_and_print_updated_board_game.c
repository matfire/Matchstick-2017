/*
** EPITECH PROJECT, 2018
** read_player_move
** File description:
** read
*/

#include <unistd.h>
#include <stdlib.h>

int my_getnbr(char *str)
{
	int res = 0;

	for (int i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';
	return (res);
}

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

int is_numeric(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] > '9' && str[i] < '0')
			return (0);
	}
	return (1);
}

void read_player_move_and_print_updated_board_game(void)
{
	char *line;
	char *matches;
	int line_nb = 0;
	int nb_matches = 0;

	my_putstr("Line:");
	line = get_next_line(0);
	if (!is_numeric(line)) {
		write(2, "Error: this line is out of range\n", 33);
		free(line);
		return;
	}
	my_putstr("Matches:");
	matches = get_next_line(0);
	if (!is_numeric(matches)) {
		write(2, "you have to remove at least one match\n", 38);
		free(matches);
		return;
	}
	line_nb = my_getnbr(line);
	nb_matches = my_getnbr(matches);
	print_updated_game_board(line_nb, nb_matches);
}
