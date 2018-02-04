/*
** EPITECH PROJECT, 2018
** errors
** File description:
** errors
*/

#include "stick.h"

int is_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (1);
	}
	return (0);
}

int check_values(char **av)
{
	if (is_number(av[1]))
		return (1);
	if (my_getnbr(av[1]) > 100 || my_getnbr(av[1]) <= 0)
		return (1);
	return (0);
}
