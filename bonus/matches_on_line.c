/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "../inc/stick.h"
#include <criterion/criterion.h>
#include <string.h>

Test(matches_on_line, simple_line)
{
	char **tab;
	tab = malloc(sizeof(char*) * 2);
	tab[0] = malloc(sizeof(char) * 10);
	tab[0] = strcpy(tab[0], "   |||   ");
	cr_assert_eq(get_matches_on_line(tab, 0), 3);
	free(tab[0]);
	free(tab);
}

Test(matches_on_line, complex_line)
{
	char **tab;
	tab = malloc(sizeof(char*) * 2);
	tab[0] = malloc(sizeof(char) * 18);
	tab[0] = strcpy(tab[0], "| |  |  | |  |  |");
	cr_assert_eq(get_matches_on_line(tab, 0), 7);
	free(tab[0]);
	free(tab);
}

Test(matches_on_line, multi_char_line)
{
	char **tab;
	tab = malloc(sizeof(char*) * 2);
	tab[0] = malloc(sizeof(char) * 22);
	tab[0] = strcpy(tab[0], "||| azeazrae |  | | |");
	cr_assert_eq(get_matches_on_line(tab, 0), 7);
	free(tab[0]);
	free(tab);
}
