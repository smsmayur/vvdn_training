/*
 * @file     : p2.c
 * @brief    : Write a program that finds all double-spaces in an
 *	       file and replaces that with a single-space.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fptr;
    int i = 1, j, count = 0;
    char *ptr_temp, ch, c_temp = '0';
    /* checking given i/p is true or not */
    if (argc < 2) {
	printf("usage: use e.g. ./a.out fname\n");
	return 0;
    }
    /* File checking and opening*/
    for (; i < argc; i++) {
	fptr = fopen(argv[i], "r");
        if (fptr == 0) {
	   printf("File is not present.\n");
	    return 0;
	}
	/* count characters in file and allocate memory for temp variable. */
	while ((ch = fgetc(fptr)) != EOF)
	    count++;

	rewind(fptr);
	ptr_temp = malloc (count + 1);
	j = 0;
	/* remove extra spaces */
	while ((ch = fgetc(fptr)) != EOF) {
	    if (ch == c_temp)
		continue;
	    ptr_temp[j++] = ch;
	    c_temp = ch;	  
	}

	fclose(fptr);
	ptr_temp[j] = '\0';
	fptr = fopen(argv[i], "w");
	/* copy modified data into file */
	for (j = 0; ptr_temp[j]; j++)
	    putc(ptr_temp[j], fptr);

	printf("extra spaces removed\n");
    }
    return 0;
}
