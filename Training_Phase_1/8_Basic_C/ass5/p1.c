/*
 * @file     : p1.c
 * @brief    : accept name and cost of the 10 products and pass the
 *			   structure to the function then compute and
 *			   display it.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#define FIXED 10

/*
 * @structure	: products
 * @brief		: This is the basic products structure.
 * @members		:
 * @name		: name of product
 * @cost		: cost of product
 */

	const struct products {
		float cost;
		char name[10];
	};

/* global declaration of variables */
int count;
float total;

/*
 * @function :total_cost
 * @param1	:count
 * @param2	:p_total.cost,p_total.name
 * @return	:void
 * @brief	:receive array of structure  and display total cost.
 * @caller	:main function
 */
void total_cost(const struct products p_total[])
{
	for (count = 0; count < FIXED; count++) {
		printf("%s: %.2f\n", p_total[count].name, p_total[count].cost);
		total += p_total[count].cost;
	}
	printf("total cost: %.2f\n", total);
}

int main(void)
{
	const struct products p_struct[FIXED];

	for (count = 0; count < FIXED; count++) {
		printf("Enter product name and it's price: ");
		scanf("%s %f", p_struct[count].name, &p_struct[count].cost);
	}
	total_cost(p_struct);
	return 0;
}
