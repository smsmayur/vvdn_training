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
