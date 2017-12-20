#include <stdlib.h>
#include <stdio.h>
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
void sort(ST **ptr, FILE *fptr)
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

