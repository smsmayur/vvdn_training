/*
 * @file     : p1.c
 * @brief    : Write a program to implement a Database which will hold
 *	       the entries from a railway ticket booking using Single
 *	       linked list. The database should be permanent
 *	       (i.e. use file to save). The database will have entries
 *	       like journey date, from station, to station, passenger
 *	       names, age, sex, birth preference, ID proof etc. There
 *	       should be options to add, delete, modify, search,
 *	       sort, print reverse the linked list
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rail_ticket {
    char name[20];
    int age;
    char sex[8];
    char J_date[12];
    char F_station[25];
    char T_station[25];
    char B_preference[20];
    char ID_name[20];
    struct rail_ticket *next;
    
}ST;

FILE *fptr;

/*
 * @function : add_end
 * @param1   : *temp
 * @param2   : stucture members
 * @brief    : This function add the new data of passenger tickets in file.
 * @return   : void
 * @caller   : main
 */


void add_end(ST **ptr)
{

    ST *temp = malloc(sizeof(ST));
    printf("Enter passenger name, age and sex\n");
    scanf("%s %d %s", temp -> name, &temp -> age, temp -> sex);
    printf("Enter passenger journey date,From station and To station\n");
    scanf("%s %s %s", temp -> J_date, temp -> F_station, temp -> T_station);
    printf("Enter passenger birth preference and ID name\n");
    scanf("%s %s", temp -> B_preference, temp -> ID_name);
    /* store data as permenent into file */
    fprintf(fptr, "%s %d %s\n", temp -> name, temp -> age, temp -> sex);
    fprintf(fptr, "%s %s %s\n", temp -> J_date, temp -> F_station, temp -> T_station);
    fprintf(fptr, "%s %s\n", temp -> B_preference, temp -> ID_name);
    /* making linked list of all ticket */
    if (*ptr == 0) {
	temp -> next = (*ptr);
	*ptr = temp;
    }
    else {
	ST *last = *ptr;
	while(last -> next != NULL)
	    last = last -> next;

	temp -> next = last -> next;
	last -> next =temp;
    }
}

/*
 * @function : delete_ticket_name
 * @param1   : *temp, **ptr, *s
 * @param2   : stucture members
 * @brief    : This function delete the tickets to our file data.
 * @return   : void
 * @caller   : main
 */
void delete_ticket_name(ST **ptr, char *s)
{
    ST *temp = (*ptr), *last;

    while (temp) {
	if (strcmp((temp -> name), s) == 0) {
	    if (strcmp((*ptr) -> name, s) == 0) {
		*ptr = (*ptr) -> next;
		if ((*ptr) -> next == 0)
		{
		    (*ptr) = (*ptr) -> next;
		    return;
		}
	    }
	    else{
		last -> next = temp -> next;
		return;
	    }
	}
	last = temp;
	temp = temp -> next;
    }
}

/*
 * @function : print
 * @param1   : *ptr
 * @param2   : stucture members
 * @brief    : This function print passenger tickets which is avilable
 *	       in our record.
 * @return   : void
 * @caller   : main
 */
void print(ST *ptr)
{
    int i = 0;
    while (ptr) {
	printf("		####Ticket %d####\n", i++ + 1);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("passenger name  : %s\nage             : %d\nsex             : %s\n", (ptr) -> name, (ptr) -> age, (ptr) -> sex);
	printf("Journey date    : %s\nFrom station    : %s\nTo station      : %s\n", (ptr) -> J_date, (ptr) -> F_station, (ptr) -> T_station);
	printf("birth preference: %s\nID name         : %s\n\n", (ptr) -> B_preference, (ptr) -> ID_name);
	(ptr) = (ptr) -> next;
    }
}

/*
 * @function : sort
 * @param1   : **ptr
 * @param2   : stucture members
 * @brief    : This function sort the tickets according to name..
 * @return   : void
 * @caller   : main
 */
void sort(ST **ptr)
{
    int ret = 1;
    while (ret != EOF) {
	ST *temp = malloc(sizeof(ST));
	ret = fscanf(fptr, "%s %d %s", temp -> name, &temp -> age, temp -> sex);
	fscanf(fptr, "%s %s %s", temp -> J_date, temp -> F_station, temp -> T_station);
	fscanf(fptr, "%s %s", temp -> B_preference, temp -> ID_name);
	
	if ((*ptr == 0) || (strcmp(temp -> name, (*ptr) -> name) < 0)) {
	    temp -> next = (*ptr);
	    *ptr = temp;
	}
	else {
	    ST *last = (*ptr);

	    while ((last -> next) && ((strcmp(last -> next -> name, temp -> name)) < 0))
		last = last -> next;

	    temp -> next = last -> next;
	    last -> next = temp;
	}
    }
}

/*
 * @function : search_name
 * @param1   : *temp, *ptr, *s
 * @param2   : stucture members
 * @brief    : This function search and display tickets according to passenger
 *	       name from our file data.
 * @return   : int
 * @caller   : main
 */
int search_name(ST *ptr, char *s_name)
{
    int count = 0;
    while (ptr) {
	if (strcmp(s_name, ptr -> name) == 0) {
	    printf("-------------------------------------------------------------------------------------------------------------------\n");
	    printf("passenger name  : %s\nage             : %d\nsex             : %s\n", ptr -> name, ptr -> age, ptr -> sex);
	    printf("Journey date    : %s\nFrom station    : %s\nTo station      : %s\n", ptr -> J_date, ptr -> F_station, ptr -> T_station);
	    printf("birth preference: %s\nID name         : %s\n\n", ptr -> B_preference, ptr -> ID_name);
	    count++;
	}
	ptr = ptr -> next;
    }
    if (count == 0)
	printf("#Name is not present.\n\n");
}

/*
 * @function : modify
 * @param1   : *ptrr, *s
 * @param2   : stucture members
 * @brief    : This function modify the info of passenger.
 * @return   : void
 * @caller   : main
 */
void modify(ST *ptrr, char *s_name)
{
    int opt;
    ST *ptr = ptrr;

    while(ptr) {
	if (strcmp(s_name, (ptr) -> name) == 0) {
	    printf("which details u want to update 1)name 2)age 3)sex 4)journey date 5)From station 6)To station 7) birth preffrnc 8)ID proof\n");
	    scanf("%d", &opt);

	    if (opt == 1) {
		char temp[20];
		printf("Enter new name\n");
		scanf("%s", temp);
		strcpy((ptr) -> name, temp);
	    }
	    else if (opt == 2) {
		int temp;
		printf("Enter new age\n");
		scanf("%d", &temp);
		(ptr) -> age = temp;
	    }
	    else if (opt == 3) {
		char temp[8];
		printf("Enter new sex\n");
		scanf("%s", temp);
		strcpy((ptr) -> sex, temp);
	    }
	    else if (opt == 4) {
		char temp[12];
		printf("Enter new date(dd/mm/yyyy)\n");
		scanf("%s", temp);
		strcpy((ptr) -> J_date, temp);
	    }
	    else if (opt == 5) {
		char temp[20];
		printf("Enter new 'From station' name\n");
		scanf("%s", temp);
		strcpy((ptr) -> F_station, temp);
	    }
	    else if (opt == 6) {
		char temp[20];
		printf("Enter new 'To station' name\n");
		scanf("%s", temp);
		strcpy((ptr) -> T_station, temp);
	    }
	    else if (opt == 7) {
		char temp[20];
		printf("Enter new Birth preference\n");
		scanf("%s", temp);
		strcpy((ptr) -> B_preference, temp);
	    }
	    else if (opt == 8) {
		char temp[20];
		printf("Enter new ID Proof name\n");
		scanf("%s", temp);
		strcpy((ptr) -> ID_name, temp);
	    }
	    printf("Updated succesfully.\n");
	    return;
	}
	(ptr) = (ptr) -> next;
    }
}

/*
 * @function : print_reverse
 * @param1   : *ptr
 * @param2   : stucture members
 * @brief    : This function print file data reversly.
 * @return   : void
 * @caller   : main
 */
void print_reverse(ST *ptr)
{
   static int i = 0;
    if (ptr) {
	/* this is recursion function call*/
	print_reverse(ptr -> next);
	printf("		####Ticket %d#####\n", (i++) + 1);
	printf("---------------------------------------------------------------------------------------------------------------------\n");
	printf("passenger name  : %s\nage             : %d\nsex             : %s\n", ptr -> name, ptr -> age, ptr -> sex);
	printf("Journey date    : %s\nFrom station    : %s\nTo station      : %s\n", ptr -> J_date, ptr -> F_station, ptr -> T_station);
	printf("birth preference: %s\nID name         : %s\n\n", ptr -> B_preference, ptr -> ID_name);
    }
}

/*
 * @function : read_file
 * @param1   : **ptr, ret.
 * @param2   : stucture members
 * @brief    : This function read data from file and display it.
 * @return   : void
 * @caller   : main
 */
void read_file(ST **ptr)
{
    int ret = 1;

    while (1) {

    ST *temp = malloc(sizeof(ST));
	fscanf(fptr, "%s %d %s", temp -> name, &temp -> age, temp -> sex);
	fscanf(fptr, "%s %s %s", temp -> J_date, temp -> F_station, temp -> T_station);
	ret = fscanf(fptr, "%s %s", temp -> B_preference, temp -> ID_name);

    if (*ptr == 0) {
	temp -> next = (*ptr);
	*ptr = temp;
    }
    else {
	ST *last = (*ptr);
	while(last -> next != NULL)
	    last = last -> next;

	temp -> next = last -> next;
	last -> next =temp;
    }
	if (ret == EOF)
	    return;
    }
}

/*
 * @function : update_file
 * @param1   : *ptr
 * @param2   : stucture members
 * @brief    : This function update data into file.
 * @return   : void
 * @caller   : main
 */
void update_file(ST *ptr)
{
    /* creat old file into Write mode and paste latest data */
    FILE *fp;
	fp = fopen("rail_ticket", "w+");
	if (fp < 0) {
	    printf("file is not present\n");
	    return;
	}
    while (ptr) {
	fprintf(fptr, "%s %d %s\n", ptr -> name, ptr -> age, ptr -> sex);
	fprintf(fptr, "%s %s %s\n", ptr -> J_date, ptr -> F_station, ptr -> T_station);
	fprintf(fptr, "%s %s\n", ptr -> B_preference, ptr -> ID_name);
	ptr = ptr -> next;
    }
    fclose(fp);
}


int main()
{
    ST *hptr = 0;
    char ch;
    char name[10];
    int opt, op;
    /* open file into append+ mode */
    fptr = fopen("rail_ticket", "a+");

    if (fptr < 0) {
	printf("file is not present..\n");
	return 0;
    }
    char c;
    /* this for select operation */
    do {
	printf("\nWhich operation do u want in ticket 1)add 2)read 3)sorting 4)delete 5)modify 6)search 7)print 8)print reverse\n ");
	scanf("%d", &opt);

	if (opt == 1) {
	    char ch;
	    do {		    
		add_end(&hptr);
		printf("Do u want to add more data (y/n)\n");
		scanf(" %c", &ch);
	    } while ((ch == 'y') || (ch == 'Y'));
	}
	else if (opt == 2) {
	    read_file(&hptr);
	    printf("\n #read succesfully.\n\n");
	    print(hptr);
	}
	else if (opt == 3) {
	    sort(&hptr);
	    print(hptr);
	}
	else if (opt == 4) {
	    read_file(&hptr);
	    char name[15];
	    printf("which name ticket u want to delete\n");
	    scanf("%s", name);
	    delete_ticket_name(&hptr,name);
	    update_file(hptr);
	    print(hptr);
	}
	else if (opt == 5) {
	    char name[15];
	    printf("which name ticket u want to modify\n");
	    scanf("%s", name);
	    modify(hptr, name);
	    update_file(hptr);
	    print(hptr);
	}
	else if (opt == 6) {
	    char name[15];
	    printf("Enter name for search.\n");
	    scanf("%s", name);
	    search_name(hptr,name);
	}
	else if (opt == 7) {
	    printf("\n");
	    print(hptr);
	}
	else if (opt == 8) {
	    printf("\n");
	    print_reverse(hptr);
	}
	else
	    printf("\n#Wrong input\n");
	printf("Do u wnt to continue operation in add end (y/n)\n");
	scanf(" %c", &c);
    } while ((c == 'Y') || (c == 'y'));
    return 0;
}
