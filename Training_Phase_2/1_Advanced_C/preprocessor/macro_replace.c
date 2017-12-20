/*
 * @file     : p1.c
 * @brief    : Program to implement the basic MACRO replacement function
 *	       of the pre-processor stage. Also the output file
 *	       should be .i file
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*
 * @function : fileread
 * @param1   : argv[i]
 * @param2   : File * temp
 * @brief    : This function read the content of given file and store in
 *            pointer to array;
 * @return   : FileData
 * @caller   : main
 */
static char *fileread(FILE *temp)
{
    char ch, *ptr_ch;
    int i = 0, count = 0;

    while ((ch = fgetc(temp)) != EOF)
	count++;
    
    rewind(temp);
    ptr_ch = malloc(count + 1);

    while ((ch = fgetc(temp)) != -1)
	ptr_ch[i++] = ch;

    ptr_ch[i] = '\0';
    rewind(temp);

    return ptr_ch;


}

/*
 * @function : macro_remove
 * @param1   : argv[i]
 * @param2   : char *filedata
 * @brief    : This function delete macro line and then search macro name
 *            and replace with its value.;
 * @return   : void
 * @caller   : main
 */
static void macro_remove(char *filedata)
{
    char *ret = filedata;
    char macro[10], m_name[10], m_body[10];
    char *dest, *rep;
    int check;
    int sl_val;
    int sl_name;
    int sl_rep;
    int size;

    /* this loop first match macro line then delete it after that it
       search macro name in file replace with macro body.	 */
    while ((ret = strstr(ret, "#define")) != NULL) {
	if (ret != NULL) {
	    check = sscanf(ret, "%s%s%s", macro, m_name, m_body);
	    if (check != 3) {
		printf("scanf fail\n");
		exit(0);
	    }
	    dest = strchr(ret, 10);
	    memmove(ret, dest, strlen(dest)+1);
	    rep = ret;

	    while ((rep = strstr(rep, m_name)) != NULL) {
		sl_name = strlen(m_name);
		sl_val = strlen(m_body);
		sl_rep = strlen(rep);
		size = sl_rep - sl_name + 1;

		memmove(rep + sl_val, rep + sl_name, size);
		strncpy(rep, m_body, sl_val);
	    }
	    ret++;
	}
    }
}

int main(int argc, char **argv)
{
    FILE *fptr;
    int i;
    char s_temp[20], **ptr;
    char *filedata;
    int sl_file;
    
    if (argc < 2) {
	printf("usage: use e.g. ./a.out fname\n");
	return 0;
    }
    /* checking file present or not */
    for (i = 0; i < argc; i++) {
	fptr = fopen(argv[i], "r");
	if (fptr < 0) {
	    printf("File is not present.\n");
	    return 0;
	}

	/* calling function */
	filedata = fileread(fptr);
	macro_remove(filedata);

	/* store data into .i file */
	sl_file = strlen(argv[i]);
	argv[i][sl_file - 1] = 'i';
	fptr = fopen(argv[i], "w+");
	fputs(filedata, fptr);
	fclose(fptr);
    }
    return 0;
}
