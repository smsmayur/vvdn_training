/*
 * @file     : p2.c
 * @brief    : this program detect a system is little-endian or big-
 *             endian.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.#include <stdio.h>
 */

#include <stdio.h>

int main(void)
{
	int i = 300;
	char ch = i;


	if (ch == 44)
	printf("system is little enedians.\n");

	else
	printf("system is big enedians.\n");
}
