#include<stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char name[20], sex[10], J_date[10];
    int age;
	fp= fopen("rail_ticket","r");

    fscanf(fp,"%s %d %s",name,&age, sex);
    fscanf(fp, "%s",J_date);

    printf("%s %d %s %s\n",name, age, sex, J_date);


}
