/*
 * @file     : p1.c
 * @brief    : input a list of real numbers of unknown length
 *	       and output : sum and count of all positive
 *	       & negative numbers. Print the output using
 *	       following cases :
 *		a) Pointer to array
 *		b) Pointer to Pointer
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>

int lp;

/*
 * @function	:positive_arr
 * @param1	:count, i, temp
 * @param2	:**p
 * @return	:void
 * @brief	:This function receive pointer and catch with double pointer.
 *		 it will separate positive numbers and print as well as sum of those
 *		 positive real numbers.
 * @caller	:main function
 */
void positive_arr(float **p_fun)
{
    int i, count;
    float temp = 0;

    printf("\npositive real  number.\n");
    for (i = 0; i < lp; i++) {
	if ((*p_fun)[i] < 0)
	    continue;
	else {
	   temp += (*p_fun)[i];
	   count++;
	printf("%.2f ", (*p_fun)[i]);
	}
    }
    printf("\nsum of positive real numbers: %.2f\n", temp);
}

/*
 * @function	:negative_arr
 * @param1	:cnt, temp, (*ptr)[lp]
 * @return	:void
 * @brief	:This function receive array and catch with pointer to a array
 *		 it separate and display negative real numbers and sum of those numbers.
 * @caller	:main function
*/
void negative_arr(float (*ptr)[lp])
{
    int cnt;
    float temp = 0;

    printf("\n\nnegative real number.\n");
    for (cnt = 0; cnt < lp; cnt++) {
	if (ptr[0][cnt] > 0)
	    continue;
	else {
	    temp += ptr[0][cnt];
	    printf("%.2f ", ptr[0][cnt]);
	}
    }
    printf("\nsum of negative real number: %.2f\n", temp);
}

int main(void)
{
    int i;
    float *p, tmp;
    char ch;

    p = malloc(sizeof(float) * 2);
    printf("Enter real numbers and press enter to end it..\n");
    /* this logic for fatching unknown length elements of array
     and also allocating Dynamic memory for each number      */
    while (1) {
	scanf("%f%c", &tmp, &ch);
	p[lp++] = tmp;
	p = realloc(p, sizeof(float) * lp);
	if (ch == '\n')
	    break;
    }
    /* this logic for copy data of pointer to array and
       passing its address for catch with pointer to an array. */
    float temp_arr[lp];

    for (i = 0; i < lp; i++)
	temp_arr[i] = p[i];
    /* function calling */
    positive_arr(&p);
    negative_arr(&temp_arr);

    return 0;
}
