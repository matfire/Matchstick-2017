/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "stick.h"

int main(int ac, char **av)
{
	char **map;
	if (ac != 2)
		return (84);
	map = create_map(my_getnbr(av[1]));
	return (0);
}
