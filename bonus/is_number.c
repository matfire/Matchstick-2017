/*
** EPITECH PROJECT, 2018
** is_number
** File description:
** is_number
*/

#include "stick.h"
#include <criterion/criterion.h>

Test(is_number, number)
{
	cr_assert_eq(is_number("123"), 0);
}

Test(is_number, phrase)
{
	cr_assert_eq(is_number("This is a number"), 1);
}

Test(is_number, mix)
{
	cr_assert_eq(is_number("1Ths3 QklK 2 dKS"), 1);
}

Test(is_number, null)
{
	cr_assert_eq(is_number(NULL), 1);
}
