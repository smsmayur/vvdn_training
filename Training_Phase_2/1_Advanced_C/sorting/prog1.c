/*
 * @file     : p1.c
 * @brief    : Program to sort array in ascending and descending order using:
 *		i)Bubble sort
 *		ii)Selection sort
 *		iii)Insertion sort
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/*
 * @function	:insert_sort
 * @param1	:i, j, temp
 * @param2	:*ptr
 * @return	:void
 * @brief	:This function receive one DMA array and then it sort array
 *               using insertion sorting.
 * @caller	:main function
 */
void insert_sort(int *ptr)
{
    int i, j, temp;
    
    /* ascending order logic */
    for (i = 0; i < MAX-1; i++) {
	for (j = 0; j <= i; j++) {
	    if (ptr[j] > ptr[i + 1]) {
		temp = ptr[j];
		ptr[j] = ptr[i + 1];
		ptr[i + 1] = temp;
	    }
	}
    }
    printf("\n            ##### insertion Sort #####\n\n");
    printf("##### Ascending order #####\n");
    for (i = 0; i < MAX; i++)
	printf("%d ", ptr[i]);
    printf("\n");

    /* descending order logic */
    for (i = 0; i < MAX; i++) {
	for (j = 0; j < i; j++) {
	    if (ptr[j] < ptr[i+1]) {
		temp = ptr[j];
		ptr[j] = ptr[i+1];
		ptr[i + 1] = temp;
	    }
	}
    }
    printf("##### Descending order #####\n");
    for (i = 0; i < MAX; i++)
	printf("%d ", ptr[i]);
    
    printf("\n");
}
/*
 * @function	:str_cmp
 * @param1	:i
 * @param2	:*str1, *str2
 * @return	:int
  * @brief	:This function receive one DMA array and then it sort array
 *               using selection sorting.
 * @caller	:main function
 */
void select_sort(int *ptr)
{
    int i, j, temp, min_ind;

    /* ascending order logic */
    for (i = 0; i < MAX - 1; i++) {
	min_ind = i;
	for (j = i + 1; j < MAX; j++) {
	    if (ptr[j] < ptr[min_ind])
		min_ind = j;
	}
		temp = ptr[i];
		ptr[i] = ptr[min_ind];
		ptr[min_ind] = temp;
    }
    printf("\n            ##### Selection Sort #####\n\n");
    printf("##### Ascending order #####\n");
    for (i = 0; i < MAX; i++)
	printf("%d ", ptr[i]);
    printf("\n");

    /* descending order logic */
    for (i = 0; i < MAX - 1; i++) {
	min_ind = i;
	for (j = i + 1; j < MAX; j++)
	    if (ptr[j] > ptr[min_ind])
		min_ind = j;
		temp = ptr[i];
		ptr[i] = ptr[min_ind];
		ptr[min_ind] = temp;
    }
    printf("##### Descending order #####\n");
    for (i = 0; i < MAX; i++)
	printf("%d ", ptr[i]);
    
    printf("\n");
}
/*
 * @function	:str_cmp
 * @param1	:i
 * @param2	:*str1, *str2
 * @return	:int
 * @brief	:This function receive one DMA array and then it sort array
 *               using Bubble sorting.
 * @caller	:main function
 */
void bubble_sort(int *ptr)
{
    int i, j, temp;
    /* ascending order logic */
    for (i = 0; i < MAX; i++) {
	for (j = 0; j < MAX - i - 1; j++) {
	    if (ptr[j] > ptr[j+1]) {
		temp = ptr[j];
		ptr[j] = ptr[j+1];
		ptr[j + 1] = temp;
	    }
	}
    }
    printf("\n            ##### Bubble Sort #####\n\n");
    printf("##### Ascending order #####\n");
    for (i = 0; i < MAX; i++)
	printf("%d ", ptr[i]);
    printf("\n");

    /* descending order logic */
    for (i = 0; i < MAX; i++) {
	for (j = 0; j < MAX - 1 - i; j++) {
	    if (ptr[j] < ptr[j+1]) {
		temp = ptr[j];
		ptr[j] = ptr[j+1];
		ptr[j + 1] = temp;
	    }
	}
    }
    printf("##### Descending order #####\n");
    for (i = 0; i < MAX; i++)
	printf("%d ", ptr[i]);
    
    printf("\n");
}
int main(int argc, char **argv)
{
    int *arr, i, num;
    char ch;
    /* allocate DM and select sorting mode*/
    do {
    arr = malloc(sizeof (int) * MAX);

    printf("Enter the array elements.\n");
    for (i = 0; i < MAX; i++)
	scanf("%d", &arr[i]);
    printf("\nwhich sorting method u want to use 1)selection 2)Bubble 3)insertion\n");
    scanf("%d",&num);
    /* function call */
    if (num == 1)
	select_sort(arr);
    else if (num == 2)
	bubble_sort(arr);
    else if (num == 3)
	insert_sort(arr);
    else
	printf("wrong input\n");

    printf("\nDo u want again operation (y/n)\n");
    scanf(" %c",&ch);
    } while ((ch == 'Y') || (ch == 'y'));
    return 0;
}

