/*
 * @file     : p2.c
 * @brief    : Using dynamic arrays, implement a polynomial class with
 *	       polynomial addition, subtraction, and multiplication.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPR 2
#define MAX_COEFF 3

struct poly{
    int coeff;
    int expr;
};

/*
 * @function	:mul_poly
 * @param1	:count, lp, lp1, max;
 * @param2	:struct poly stat_mul[][], struct poly mul_out
 * @return	:void
 * @brief	:This function receive 2d array of structure and display 
 *		 polynomial multiplication.
 * @caller	:main function.
 */
void mul_poly(struct poly stat_mul[MAX_EXPR][MAX_COEFF])
{
    struct poly mul_out[MAX_COEFF];
    int lp, lp1, lp2, count = 0, max = MAX_COEFF, j;

    for (lp = 0; lp < MAX_EXPR; lp++) {
	for (lp1 = 0; lp1 < max; lp1++) {
	    for (lp2 = 0, count = 0; lp2 < max; lp2++) {
		if (stat_mul[lp][lp1].expr == stat_mul[lp+1][lp2].expr) {
		    mul_out[lp1].coeff = stat_mul[lp][lp1].coeff * stat_mul[lp+1][lp2].coeff;
		    printf("%dx^%d ", mul_out[lp1].coeff, stat_mul[lp][lp1].expr);
		    for (j = lp2; j < max; j++)
			stat_mul[lp+1][j] = stat_mul[lp+1][j+1];
		    count++;
		    max--;
		    if ((lp + 1) == MAX_EXPR)
			continue;
		    else
			printf(" * ");
		}
	    }
	    if (count == 0) {
		printf("%dx^%d", stat_mul[lp][lp1].coeff, stat_mul[lp][lp1].expr);
		if ((lp1 + 1) == max)
		    continue;
		else
		    printf(" * ");
	    }
	}
    }
    printf("\n");
}
/*
 * @function	:sub_poly
 * @param1	:count, lp, lp1, max;
 * @param2	:struct poly stat_sub[][], struct poly sub_out
 * @return	:void
 * @brief	:This function receive 2d array of structure and display 
 *		 polynomial subtraction.
 * @caller	:main function.
 */
void sub_poly(struct poly stat_sub[MAX_EXPR][MAX_COEFF])
{
    struct poly sub_out[MAX_COEFF];
    int lp, lp1, lp2, count = 0, max = MAX_COEFF, j;

    for (lp = 0; lp < MAX_EXPR; lp++) {
	for (lp1 = 0; lp1 < max; lp1++) {
	    for (lp2 = 0, count = 0; lp2 < max; lp2++) {
		if (stat_sub[lp][lp1].expr == stat_sub[lp+1][lp2].expr) {
		    sub_out[lp1].coeff = stat_sub[lp][lp1].coeff - stat_sub[lp+1][lp2].coeff;
		    printf("%dx^%d ", sub_out[lp1].coeff, stat_sub[lp][lp1].expr);
		    for (j = lp2; j <= max; j++)
			stat_sub[lp+1][j] = stat_sub[lp+1][j+1];
		    count++;
		    max--;
		    if ((lp + 1) == MAX_EXPR)
			continue;
		    else
			printf(" - ");
		}
	    }
	    if (count == 0) {
		printf("%dx^%d", stat_sub[lp][lp1].coeff, stat_sub[lp][lp1].expr);
		if ((lp1 + 1) == max)
		    continue;
		else
		    printf(" - ");
	    }
	}
    }
    printf("\n");
}

/*
 * @function	:add_poly
 * @param1	:count, lp, lp1, max;
 * @param2	:struct poly stat_add[][], struct poly add_out
 * @return	:void
 * @brief	:This function receive 2d array of structure and display 
 *		 polynomial addition.
 * @caller	:main function.
 */
void add_poly(struct poly stat_add[MAX_EXPR][MAX_COEFF])
{
    struct poly add_out[MAX_COEFF];
    int lp, lp1, lp2, count = 0, max = MAX_COEFF, j;

    for (lp = 0; lp < MAX_EXPR; lp++) {
	for (lp1 = 0; lp1 < max; lp1++) {
	    for (lp2 = 0, count = 0; lp2 < max; lp2++) {
		if (stat_add[lp][lp1].expr == stat_add[lp+1][lp2].expr) {
		    add_out[lp1].coeff = stat_add[lp][lp1].coeff + stat_add[lp+1][lp2].coeff;
		    printf("%dx^%d ", add_out[lp1].coeff, stat_add[lp][lp1].expr);
		    for (j = lp2; j < max; j++)
			stat_add[lp+1][j] = stat_add[lp+1][j+1];
		    count++;
		    max--;
		    if ((lp + 1) == MAX_EXPR)
			continue;
		    else
			printf(" + ");
		}
	    }
	    if (count == 0) {
		printf("%dx^%d", stat_add[lp][lp1].coeff, stat_add[lp][lp1].expr);
		if ((lp1 + 1) == max)
		    continue;
		else
		    printf(" + ");
	    }
	}
    }
    printf("\n");
}

int main(void)
{
    struct poly stat[MAX_EXPR][MAX_COEFF];
    int lp, lp1, number;

    printf("Which operation do u want to select number 1) addition 2)subtraction 3)multiplication\n");
    scanf("%d",&number);
    /* this logic scan expression from user */
    for (lp = 0; lp < MAX_EXPR; lp++) {
	printf("\nEnter %d expression.\n\n", lp+1);
	for (lp1 = 0; lp1 < MAX_COEFF; lp1++) {
	    printf("Enter expression and coefficient: ");
	    scanf("%d %d",&stat[lp][lp1].coeff, &stat[lp][lp1].expr);
	}
    }
    /* it is print the expression and coeff into form of equestion */
    for (lp = 0; lp < MAX_EXPR; lp++) {
	for (lp1 = 0; lp1 < MAX_COEFF; lp1++) {
	    printf("%dx^%d ", stat[lp][lp1].coeff, stat[lp][lp1].expr);
	    /* according operation select sign */
	    if ((lp1 + 1) == MAX_COEFF)
		continue;
	    else {
		if (number == 1)
		    printf(" + ");
		else if (number == 2)
		    printf(" - ");
		else if (number == 3)
		    printf(" * ");
	    }
	}
	printf("\n");
    }
    printf("\n-------------------------------------------------------------------\n");
    /* selct operation */
    switch (number) {
	case 1:	add_poly(stat);
		break;
	case 2: sub_poly(stat);
		break;
	case 3: mul_poly(stat);
		break;
	default : printf("Thank u..\n");
		  break;
    }

    return 0;
}
