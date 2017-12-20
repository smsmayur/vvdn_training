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
	fprintf(fp, "%s %d %s\n", ptr -> name, ptr -> age, ptr -> sex);
	fprintf(fp, "%s %s %s\n", ptr -> J_date, ptr -> F_station, ptr -> T_station);
	fprintf(fp, "%s %s\n", ptr -> B_preference, ptr -> ID_name);
	ptr = ptr -> next;
    }
    fclose(fp);
}
