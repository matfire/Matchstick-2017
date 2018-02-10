/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "stick.h"
#include "get_next_line.h"

int main(int ac, char **av)
{
	char **map;

	if (ac != 3 || check_values(av))
		return (84);
	map = create_map(my_getnbr(av[1]));
	print_board(map);
	srandom(time(NULL) + getpid());
	while (1) {
	if (player_turn(map, my_getnbr(av[2])))
		break;
	if (check(map))
		return (2);
	ai_turn(map);
	if (check(map))
		return (1);
	}
	return (0);
}
