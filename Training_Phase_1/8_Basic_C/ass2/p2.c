/*
 * @file     : p2.c
 * @brief    : There are 21 matchsticks.Maximum number of matchsticks a player
 *			   can pick is 4.i.e The player can pick 1, 2, 3, or 4
 *			   matchsticks.After the person picks, the computer
 *			   does its picking.Whoever is forced to pick up the
 *			   last matchstick loses the game.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int cpu = 5, i, j, totel = 21, num_u;
	char user[10];

	for (i = 0; i <= 4; i++) {
	if (totel == 1) {
	printf("there is totel %d matchstick and Game over.\n", totel);
	break;
	}

again:printf("\nthere is totel %d matchstick %d turn.\n", totel, i+1);
	printf("Enter number between 1 to 4.\n");
	scanf("%s", user);
	num_u = atoi(user);

	if (!((num_u >= 1) && (num_u <= 4))) {
	printf("\nplease Enter a valid number.");
	goto again;
	}
	cpu -= num_u;
	totel -= 5;
	cpu = 5;
	}
	printf("Ohh! you lose the Game.\n");
	return 0;
}
