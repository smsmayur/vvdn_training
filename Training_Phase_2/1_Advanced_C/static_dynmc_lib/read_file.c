#include <stdlib.h>
#include <stdio.h>
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
void read_file(ST **ptr, FILE *fptr)
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
