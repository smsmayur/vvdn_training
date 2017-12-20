/*
 * @file     : p3.c
 * @brief    : program accept train name and arrival time
 *			   of 5 trains.and display with railway time
 *			   format.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>

#define TRAIN_COUNT 5

/*
 * @structure	: time_details
 * @brief		: This is for basic time details.
 * @members		:
 * @hour		: for hour
 * @min		    : for min
 * @am_pm       : am pm format
 */

struct time_details {
    unsigned  int hour;
    unsigned int min;
    char am_pm[3];
};

/*
 * @structure	: train_details
 * @brief		: This is for trains details with time.
 * @members		:
 * @name_train	: name of train
 * @time	    : it is nested structure variable.
 */
struct train_details {
    char name_train[20];
    struct time_details time;
};

/* global declaration of variables */
int lp;

/*
 * @function:train_dysplay
 * @param1	:train
 * @param2	:lp
 * @return	:void
 * @brief	:it display train name with arrival time.
 * @caller	:main function
 */
void train_display(struct train_details train[TRAIN_COUNT])
{
	printf("\n  TRAIN NAME\t\tARRIVAL TIME\n");
	for (lp = 0; lp < TRAIN_COUNT; lp++)
		printf("%d)  %s  \t\t%u:%u %s\n", lp+1, train[lp].name_train, \
		train[lp].time.hour, train[lp].time.min, train[lp].time.am_pm);
}

int main(void)
{
	struct train_details train_var[TRAIN_COUNT];

	for (lp = 0; lp < TRAIN_COUNT; lp++) {
		printf("\nEnter Train%d name: ", lp+1);
		scanf("%s", train_var[lp].name_train);
		printf("Enter time with hour:min AM/PM format :");
		scanf("%d %d %s", &train_var[lp].time.hour,
		&train_var[lp].time.min, train_var[lp].time.am_pm);
		/* this logic for value should be within exact time */
		if ((train_var[lp].time.hour >= 1) && (train_var[lp].time.hour <= 12));

		else {
			printf("usage: enter hour between 1 to 12 ex. 01:12 AM\n");
			return 0;
		}
		if ((train_var[lp].time.min >= 0) && (train_var[lp].time.min <= 59))
			continue;

		else {
			printf("usage: enter min between 0 to \
					 59 ex. 00:59 AM\n");
			return 0;
		}
	}
	train_display(train_var);
	return 0;
}
