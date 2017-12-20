/*
 * @file     : p1.c
 * @brief    : print binary of two numbers and also print no. of bits
 *			   differents.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>

int main(void)
{
	int num1, num2, i, c = 0;

	printf("Enter the 2 value :\n");
	scanf("%d %d", &num1, &num2);
	do {
		if (c == 0) {
			for (i = 31; i >= 0; i--)
			(num1>>i&1) ? printf("1") : printf("0");
			c++;
			printf("\n");
	}

	else {
		for (i = 31; i >= 0; i--)
		(num2>>i&1) ? printf("1") : printf("0");
		c++;
		printf("\n");
	}
	} while (c <= 1);
	for (i = 31, c = 0; i >= 0; i--)
		if ((num1 >> i&1) != (num2 >> i&1))
		c++;

	}
	printf("No. of Different bits is %d\n", c);
	return 0;
}
