/*
 * @file     : p1.c
 * @brief    : add two 2D arrays of variable dimension Function should catch
 *			   1st array using Pointer to an array and 2nd using
 *			   array of pointers. Print the resultant array using
 *			   a user defined.print() function which catches a
 *			   2D array using double pointer.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>

#define arr1_row 2
#define arr1_col 3
#define arr2_row 2
#define arr2_col 3
#define arr2_ptr_col arr1_col

/* global declaration of variables */
int count, count1, arr1[arr1_row][arr1_col], arr2[arr2_row][arr2_col],
*arr2_ptr[arr2_ptr_col], result[arr1_row][arr1_col], *result_arr_ptr[3];

/*
 * @function :print
 * @param1	:count, count1
 * @param2	:**result_arr
 * @return	:void
 * @brief	:This function receive resultant array and display it.
 * @caller	: add_2d function
 */
void print(int **result_arr)
{
	printf("Result Array: ");
	for (count = 0; count < arr1_row; count++)
		for (count1 = 0; count1 < arr1_col; count1++)
			printf("%d ", *(*(result_arr + count) + count1));
	printf("\n");
}

/*
 * @function :add_2d
 * @param1	:count, count1
 * @param2	:result_arr_ptr,result arry
 * @return	:void
 * @brief	:This function receive array of pointer and
 * pointer to an array and add this 2 2d array then send to print function.
 * @caller	:main function
 */
void add_2d(int (*ptr_arr1)[arr1_col], int *arr2_ptr[arr2_row])
{
	for (count = 0; count < arr1_row; count++)
		for (count1 = 0; count1 < arr1_col; count1++)
			result[count][count1] = ptr_arr1[count][count1]
			+ arr2_ptr[count][count1];
/* adding two array values and store into result array */
	for (count = 0; count < arr2_ptr_col; count++)
	result_arr_ptr[count] = result[count];
	print(result_arr_ptr);
}

int main(void)
{
	if ((arr1_row != arr2_row) || (arr1_col != arr2_col)) {
		printf("usage: enter same row and column size of arrays\n");
		return 0;
	}	

	printf("Enter the first array1 elements.\n");
	for (count = 0; count < arr1_row; count++)
		for (count1 = 0; count1 < arr1_col; count1++)
			scanf("%d", &arr1[count][count1]);

	printf("Enter the first array2 elements.\n");
	for (count = 0; count < arr2_row; count++)
		for (count1 = 0; count1 < arr2_col; count1++)
			scanf("%d", &arr2[count][count1]);
/* this is moving data from array2 to array of pointer. */
	for (count = 0; count < arr2_ptr_col; count++)
		arr2_ptr[count] = arr2[count];
	add_2d(arr1, arr2_ptr);
	return 0;
}
