/*
 * @file     : p3.c
 * @brief    : Get the amount of gold (in grams) and aluminium (in grams) in
 *			   a mixture and give in the % of gold in the mixutre.
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
	float g;
	int al;

	printf("Enter the value of GOLD and ALUMINIUM:\n");
	scanf("%f %d", &g, &al);
	g = (g / (g+al)) * 100;
	printf("%.2f%% GOLD in the Mixture.\n", g);
}
