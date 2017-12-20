#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    char *p = malloc(10);
    *p = 'a'; 

    char c = *p; 

    printf("\n [%c]\n",c); 
//    free(p);
    return 0;
}
