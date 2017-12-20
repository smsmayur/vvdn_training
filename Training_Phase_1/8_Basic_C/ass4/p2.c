/*
 * @file     : p2.c
 * @brief    : add two arrays of variable and store into another array
 *			   and print it.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>

#define x_size  3
#define y_size  3

/* global declaration of variables */
int count, x[x_size], y[y_size], z[x_size];

/*
 * @function :add_arr
 * @param1	:count
 * @param2	:*x_ptr, *y_ptr
 * @return	:void
 * @brief	:This function receive 2 arrays and sum it.
 * @caller	:main function
 */
void add_arr(int *x_ptr, int *y_ptr)
{
	for (count = 0; count < x_size; count++) {
			z[count] = x_ptr[count] + y_ptr[count];
			printf("%d ", z[count]);
	}
	printf("\n");
}

int main(void)
{
	if ((x_size != y_size)) {
		printf("usage: enter same index size of arrays\n");
		return 0;
	}	

	printf("Enter the first array1 elements.\n");
	for (count = 0; count < x_size; count++)
			scanf("%d", &x[count]);

	printf("Enter the first array2 elements.\n");
	for (count = 0; count < y_size; count++)
			scanf("%d", &y[count]);
	add_arr(x, y);
	return 0;
}
