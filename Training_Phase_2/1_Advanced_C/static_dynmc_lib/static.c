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

void add_end(ST **, FILE *);
void read_file(ST **, FILE *);
void sort(ST **, FILE *);
void delete_ticket_name(ST **, char *);
void update_file(ST *);
void search_name(ST *, char *);
void print(ST *);
void print_reverse(ST *);
void modify(ST *, char *);

FILE *fptr;

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
		add_end(&hptr, fptr);
		printf("Do u want to add more data (y/n)\n");
		scanf(" %c", &ch);
	    } while ((ch == 'y') || (ch == 'Y'));
	}
	else if (opt == 2) {
	    read_file(&hptr, fptr);
	    printf("\n #read succesfully.\n\n");
	    print(hptr);
	}
	else if (opt == 3) {
	    sort(&hptr, fptr);
	    print(hptr);
	}
	else if (opt == 4) {
	    read_file(&hptr, fptr);
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
