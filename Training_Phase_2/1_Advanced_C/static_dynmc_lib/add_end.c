#include <stdio.h>
#include <stdlib.h>
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
void add_end(ST **ptr, FILE *fptr)
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

