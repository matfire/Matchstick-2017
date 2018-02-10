/*
** EPITECH PROJECT, 2018
** errors
** File description:
** errors
*/

#include "stick.h"

int is_number(char *str)
{
	if (str == NULL)
		return (1);
	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (1);
	}
	return (0);
}

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}

int check_values(char **av)
{
	if (is_number(av[1]))
		return (1);
	if (my_getnbr(av[1]) >= 100 || my_getnbr(av[1]) <= 0) {
		my_puterror("Error: please enter a value between 1 and 99");
		return (1);
		}
	return (0);
}
