/*
 * @file     : p2.c
 * @brief    : search the char1. in given string and replace it with char2.
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
	int i;
	char string1[100], char1, char2, tmp[100];

	printf("Enter the string: ");
	gets(string1);
	printf("Enter the char1 with u want to replace: ");
	scanf(" %c", &char1);
	printf("Enter the char2 what u want to replace: ");
	scanf(" %c", &char2);
	strcpy(tmp, string1);

	for (i = 0; string1[i]; i++)
		if (string1[i] == char1)
		string1[i] = char2;

	if ((strcmp(string1, tmp)) == 0)
	printf("No changes in string: %s\n", string1);
	else
	printf("replaced string: %s\n", string1);
	return 0;
}
