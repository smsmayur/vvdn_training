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
