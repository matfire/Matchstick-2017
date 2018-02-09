/*
** EPITECH PROJECT, 2018
** print_status
** File description:
** print_status
*/

#include "stick.h"

void print_ia_moves(int line, int matches)
{
	my_putstr("IA removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putstr("\n");
}
