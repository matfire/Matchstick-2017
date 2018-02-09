/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** str to int
*/

#include "stick.h"

int my_getnbr(char *str)
{
	int res = 0;

	if (str == NULL)
		return (res);
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i)
		res = res * 10 + str[i] - '0';
	return (res);
}
