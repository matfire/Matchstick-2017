/*
** EPITECH PROJECT, 2018
** board_gen
** File description:
** board_gen
*/

#include <criterion/criterion.h>
#include "stick.h"

Test(create_map, low_size)
{
	char **got;
	char **expected;

	got = create_map(3);
	expected = malloc(sizeof(char*) * 6);
	expected[5] = NULL;
	expected[0] = malloc(sizeof(char) * 8);
	expected[0] = strcpy(expected[0], "*******");
	expected[1] = malloc(sizeof(char) * 8);
	expected[1] = strcpy(expected[1], "*  |  *");
	expected[2] = malloc(sizeof(char) * 8);
	expected[2] = strcpy(expected[2], "* ||| *");
	expected[3] = malloc(sizeof(char) * 8);
	expected[3] = strcpy(expected[3], "*|||||*");
	expected[4] = malloc(sizeof(char) * 8);
	expected[4] = strcpy(expected[4], "*******");
	for (int i = 0; expected[i] != NULL; i++) {
		cr_assert_str_eq(got[i], expected[i]);
	}
}
