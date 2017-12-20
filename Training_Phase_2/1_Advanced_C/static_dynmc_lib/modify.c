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
		strcpy((ptr) -> ID_name, temp);
	    }
	    printf("Updated succesfully.\n");
	    return;
	}
	(ptr) = (ptr) -> next;
    }
}

