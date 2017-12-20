/*
 * @file     : p1.c
 * @brief    : Write a Program to implement the "strcmp" functions
 *	       without using pre-defined functions. Get the input from
 *	       command line. 
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <string.h>


/*
 * @function	:str_cmp
 * @param1	:i
 * @param2	:*str1, *str2
 * @return	:int
 * @brief	:This function receive 2 strings from main and then it will 
 *		 compare both are same or not.
 * @caller	:main function
 */
int str_cmp(char *str1, char *str2)
{
    int i;
    /* string compare */
    for (i = 0; str1[i]; i++)
	if (str1[i] != str2[i]) {
	    printf("strings are not same.\n");
	    return 1;
	}
    return 0;
}

int main(int argc, char **argv)
{
    int ret = 0;

    if (argc < 3) {
	printf ("usage: enter correct data.(e.g. ./a.out str1 str2)\n");
	return 0;
    }
    /* if the length is not same no need to check chars.
       come out from function. */
    if (strlen(argv[1]) != strlen(argv[2])) {
	printf("strings are not same\n");
	return 0;
    }
    else {
	/* it receive return value from strcmp function and then will display
	   output according return type.  */
	ret = str_cmp(argv[1],argv[2]);
	if (ret == 0)
	    printf("Strings are same\n");
    }
    return 0;
}

