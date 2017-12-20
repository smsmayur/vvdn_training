/*
 * @file     : p1.c
 * @brief    : program will find, search and replace text strings.
 *
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j, k, c, string1_l1, string2_l2, string3_l3;
	char string1[100], string2[20], string3[20];

	printf("Enter the string1: ");
	gets(string1);
	printf("Enter the string2 with u want to replace: ");
	gets(string2);
	printf("Enter the string3 what u want to replace: ");
	gets(string3);

	string1_l1 = strlen(string1);
	string2_l2 = strlen(string2);
	string3_l3 = strlen(string3);

	for (i = 0; string1[i]; i++) {
		if (string1[i] == string2[0]) {
			for (j = 1; string2[j]; j++)
			if (string1[i+j] != string2[j])
			break;
		if (string2[j] == '\0') {
			string1_l1 = string1_l1 - string2_l2 + string3_l3;
			/* this logic for remove word */
			for (c = string2_l2; c > 0; c--)
			for (k = i; string1[k]; k++)
			string1[k] = string1[k+1];

			/* this logic for adding space for new words */
			for (c = string3_l3; c > 0; c--)
			for (k = string1_l1; k >= i; k--)
			string1[k+1] = string1[k];

			/* this logic for pasting replace string */
			for (k = 0; k < string3_l3; k++)
			string1[i+k] = string3[k];
		}
		}
	}
	printf("\nreplaced string: %s\n", string1);
	return 0;
}
