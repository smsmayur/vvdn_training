/*
 * @file     : p1.c
 * @brief    : Write a Program to implement the "head" command
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    FILE *fptr;
    int i = 3, j, max, opt;
    long int f_ptr, temp = 0;
    char str_tmp[100], ch;
    /* checking given proper i/p or not */
    if (argc < 4) {
	printf("usage: use e.g. ./a.out -opt N fname\n");
	return 0;
    }
    /* this is for copy MAX line */
    max = atoi(argv[2]);
   /* to get the lines and chars according input option. */
    while ((opt = getopt(argc, argv, "cn:")) != -1) {
	switch(opt) {

	    case 'n':	for (; i < argc; i++) {
			    printf("\n##### File %d lines ####\n", i-2);
			    /* checking file present or not */
			    fptr = fopen(argv[i], "r");
			    if (fptr == 0) {
				printf("File is not present.\n");
				return 0;
			    }
			    /* print lines from files */
			    for (j = 0; j < max; temp = f_ptr, j++) {
				fgets(str_tmp, 100, fptr);
				f_ptr = ftell(fptr);
				if ( f_ptr == temp)
				    return 0;
				printf("%s",str_tmp);
			    }
			}

	    case 'c':	for (; i < argc; i++) {
			    printf("\n##### File %d lines ####\n", i-2);
			    /* checking file present or not */
			    fptr = fopen(argv[i], "r");
			    if (fptr == 0) {
				printf("File is not present.\n");
				return 0;
			    }
			    /* print characters from files */
			    for (j = 0; j< max; j++) {
				ch = fgetc(fptr);
				if (ch == EOF)
				    break;
				printf("%c", ch);
			    }
			    printf("\n");
			}
	}
    }
    return 0;
}

