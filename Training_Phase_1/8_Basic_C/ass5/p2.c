/*
 * @file     : p2.c
 * @brief    : a program that will accept the cricket match performance
 *			   details (runs scored, catches taken, wikets taken
 *			   etc of every player in a match. This data will
 *			   be entered according to the team for a match and
 *			   display the total stats of all the player for the
 *			   series performance.
 * @author   : MAYUR SHANKARIYA(shankariya.mayur@vvdntech.in)
 * @Copyright: (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *             Permission is hereby granted to everyone in VVDN Technologies
 *             to use the Software without restriction, including without
 *             limitation the rights to use, copy, modify, merge, publish,
 *             distribute, distribute with modifications.i#include <stdio.h>
 */

#include <stdio.h>
#include <string.h>

/* Macros of team, players and series sizes */
#define TM_SIZE 2
#define SERIES_SIZE 1
#define PL_SIZE 2

/*
 * @structure	: player_info
 * @brief		: This consist of cricket players info.
 * @members		:
 * @pl_name[10] : player name
 * @runs_scored : runs scored
 * @balls_faced : balls faced
 * @balls_bowled: balls bowled
 * @fours		: four
 * @sixes		: six
 * @wickets_taken: wickets taken
 * @catches_taken: catches taken
 * @runs_given	: runs given
 */

struct player_info {
	char pl_name[10];
	int runs_scored;
	int balls_faced;
	int balls_bowled;
	int fours;
	int sixes;
	int wickets_taken;
	int catches_taken;
	int runs_given;
};

/* global declaration of variables */
int lp, lp1, lp2;
char name[10], ch;

/*
 * @function :total_stats
 * @param1	:lp, lp1, lp2
 * @param2	:struct player_info
 * @return	:void
 * @brief	:receive 3D array of series of team of players and search it in
 *			 given data then display total details of those
 *			 performence.
 * @caller	:main function
 */
void total_stats(const struct player_info s1[SERIES_SIZE][TM_SIZE][PL_SIZE])
{
	do {
	struct player_info s2 = {};

	printf("\nEnter name which player details you want:");
	scanf("%s", name);
	printf("\n\t|||||%s|||||\n", name);
	for (lp = 0; lp < SERIES_SIZE; lp++) {
		for (lp1 = 0; lp1 < TM_SIZE; lp1++) {
			for (lp2 = 0; lp2 < PL_SIZE; lp2++) {
				if (strcmp(name, s1[lp][lp1][lp2].pl_name) == 0) {
					s2.runs_scored += s1[lp][lp1][lp2].runs_scored;
				    s2.balls_faced += s1[lp][lp1][lp2].balls_faced;
					s2.balls_bowled += s1[lp][lp1][lp2].balls_bowled;
					s2.fours += s1[lp][lp1][lp2].fours;
					s2.sixes += s1[lp][lp1][lp2].sixes;
					s2.wickets_taken += s1[lp][lp1][lp2].wickets_taken;
					s2.catches_taken += s1[lp][lp1][lp2].catches_taken;
					s2.runs_given += s1[lp][lp1][lp2].runs_given;
				}
			}
		}
	}
	/* this Logic for after calculating data display the total data of player */
	printf("\n-> runs scored and ball faced: %d %d", s2.runs_scored, s2.balls_faced);
	printf("\n-> balls bowled: %d", s2.balls_bowled);
	printf("\n-> fours and sixes: %d %d", s2.fours, s2.sixes);
	printf("\n-> wicket taken and catch taken: %d %d", s2.wickets_taken, s2.catches_taken);
	printf("\n-> runs given: %d\n", s2.runs_given);
	printf("Do u want to search again (y/n)");
	scanf(" %c", &ch);
	} while ((ch == 'Y') || (ch == 'y'));
}

int main(void)
{
	struct player_info s[SERIES_SIZE][TM_SIZE][PL_SIZE];
	/* scanning all datas of players from user */
	for (lp = 0; lp < SERIES_SIZE; lp++) {
		printf("	##series %d##\n", lp+1);
		for (lp1 = 0; lp1 < TM_SIZE; lp1++) {
			printf("\nEnter details for TEAM%d only.\n", lp1+1);
			for (lp2 = 0; lp2 < PL_SIZE; lp2++) {
				printf("\n!!!Enter player%d detailes!!!", lp2+1);
				printf("\nEnter player NAME: ");
				scanf("%s", s[lp][lp1][lp2].pl_name);
				printf("Enter info player has runs scored and ball faced: ");
				scanf("%d %d", &s[lp][lp1][lp2].runs_scored, &s[lp][lp1][lp2].balls_faced);
				printf("Enter info for player has balls bowled: ");
				scanf("%d", &s[lp][lp1][lp2].balls_bowled);
				printf("Enter info for player has hit fours and sixes: ");
				scanf("%d %d", &s[lp][lp1][lp2].fours, &s[lp][lp1][lp2].sixes);
				printf("Enter info for player wicket taken and catch taken: ");
				scanf("%d %d", &s[lp][lp1][lp2].wickets_taken, &s[lp][lp1][lp2].catches_taken);
				printf("Enter info for player has run given: ");
				scanf("%d", &s[lp][lp1][lp2].runs_given);
			}
		}
	}
	printf("-------------------------------------------------------------\n");
	/* call to total_stats function */
	total_stats(s);
	return 0;
}
