/*
 * @file     : p3.c
 * @brief    : Remove all duplicate characters from a string.
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
	int i, j, k;
	char string1[100], tmp[100];

	printf("Enter the string: ");
	gets(string1);
	strcpy(tmp, string1);

	for (i = 0; string1[i]; i++) {
		for (j = i + 1; string1[j]; j++)
		if (string1[i] == string1[j]) {
		for (k = j; string1[k]; k++)
		string1[k] = string1[k + 1];
		j--;
		}
	}
	if ((strcmp(string1, tmp)) == 0)
	printf("no duplicate in string: %s\n", string1);

	else
	printf("duplicate present: %s\n", string1);
	return 0;
}
