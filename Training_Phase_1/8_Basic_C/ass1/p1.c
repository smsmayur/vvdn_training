/*
 * @file     : p1.c
 * @brief    : Assume 2.54 centimeters per inch, and 12 inches per foot. If the
 *             input value is 333.3,
 *             the output format should be: 333.3 centimeters is 10 feet 11.2
 *             inches.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>

#define INCH 12
#define CM 2.54

int main(void)
{
	float inch, cm, tmp;
	int feet;

	printf("Enter the centimeter value :\n");
	scanf("%f", &cm);
	tmp	= cm/(INCH*CM);
	feet = tmp;
	inch = ((tmp-feet)*INCH);
	printf("\n%.2f centimeters = %dfeets %.1finches\n", cm, feet, inch);
	return 0;
}
