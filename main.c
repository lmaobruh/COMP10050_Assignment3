/*
 * main.c
 *
 *  Created on: 2 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "crossfireOperations.h"

char Hill[5]="Hill",Ground[7]="Ground",City[5]="City"; // slot type strings to be used when assigning slot types

int main(void){

	srand(time(NULL));

	//int row = 3, column =3;

	int boardSize = 7;

	//pointer to slot (0,0)
	struct slot *upLeft;

	//pointer to slot (0,boardSize -1)
	struct slot *upRight;

	//pointer to slot (boardSize - 1, 0)
	struct slot *downLeft;

	//pointer to slot (boardSize - 1, boardSize -1)
	struct slot *downRight;


	struct slot ** board = malloc(boardSize * sizeof(struct slot *)); // allocate memory to board

			//Creates the board
			createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight, board); // call create board function

			slotAdj(board); // function to assign each slot with a string value corresponding to how many slots are adjacent NOTE: See slotAdj.c for definition

			

	int maxPlayers; // maxPlayers is the variable that the user inputs max 6 used as index size for struct array player

	printf("How many players will play (Maximum 6!)\n"); // prompt user
	

	do{ // do while maxPlayers is greater then allowed max players or lower then minimum

		puts("players must be >= 2 <= 6\n");
		scanf("%d%*c",&maxPlayers); // user input stored in max players. set number of players

	}while(maxPlayers>6 || maxPlayers < 2);

	struct Player *player = calloc(maxPlayers, sizeof(struct Player)); // declare ans dynammically allocate memory to struct array player with calloc. See crossops.h for struct Player declaration

	for(size_t i=0;i<maxPlayers;i++){ // loop to fill struct type Player_Name

		printf("Please enter name for player %zd\n",i); // prompt user
		

		scanf("%s%*c",player[i].Player_Name); // iterates through player array and gives each player a user input name

	}// end loop
	for(size_t i=0;i<maxPlayers;i++){ // loop to fill struct type PLayer_Type

		printf("Please enter player %zd type\n",i);
		
		scanf("%s%*c",player[i].Player_Type); // stores Player_Type. Player Type is referenced when distributing player capabilities. NOTE: Types must must entered in the format of Elf,Wizard,Human,Ogre. Capital letter first!!
	} // end of loop

	for(size_t i=0;i<maxPlayers;i++){ // loop iterates through each player and assigns capabilities based on player type

		AssignType(&player[i]); // call to function AssignType. See AssignType.c
	} // end loop

	for(size_t i=0;i<maxPlayers;i++){ // prints each players capabilties, name and type.

		printf("Player type is: %s\n",player[i].Player_Type);
		printf("Player Name is: %s\n",player[i].Player_Name);
		printf("Player Life-points: %.1f\n",player[i].lifePoints);
		printf("Dexterity: %d\n",player[i].Dexterity);
		printf("Luck: %d\n",player[i].Luck);
		printf("Magic Skills: %d\n",player[i].magicSkills);
		printf("Smartness: %d\n",player[i].Smartness);
		printf("Strength: %d\n",player[i].Strength);
		printf("\n");
	}

	//for Random player assignment to slot, save slot number and position
	for(size_t i=0;i<maxPlayers;i++){ // loop to assign a random slot to player[i]

		int rnd = rand()%7+0; // random number between 0 and 6
		int rnd1 = rand()%7+0; // random number between 0 and 6

		player[i].pRow = rnd; // assign random number ^ to pRow corresponds to initial row of player
		player[i].pCol = rnd1; // assign random number to pCol corresponds to initial column of player

		int pRow, pCol;

		pRow = player[i].pRow; // store pRow in player[i].pRow used in board[pRow][] to assign slots
		pCol = player[i].pCol; // same as ^ with columns



		printf("Player %s has been assigned to slot(%d, %d) Type: %s\n",player[i].Player_Name, board[pRow][pCol].row, board[pRow][pCol].column, board[pRow][pCol].Slot_Type); // slot[rnd] will be a random index value which will give back a random slot type
		strcpy(player[i].Current_Pos,board[rnd][rnd1].Slot_Type); // copies slot type to current_position of player. This will be how we keep track of and modify capabilities according to rules of the game. Will be updated after each turn.

		board[rnd][rnd1].counter = 1; // counter to track if slot is filled with player

		board[rnd][rnd1].Slot_Tag = i; // slot rnd slot tag is assigned i, will be int from 0 to 5 represnting player[0], player[1] etc. keeps track of player present in slot. used for attack function

		if(strcmp(player[i].Current_Pos,Hill)==0){ // modifies player capabilities based on assigned slot type
			 ModStr(&player[i]);
		}
		else if(strcmp(player[i].Current_Pos,City)==0){ // same as above
			ModMag(&player[i]);
		}
	}

	printf("\n");

	int input = 0;
		do{ // start of game loop will do compound statement while input is > 1. Did not have time to implement players dying

			for(size_t i = 0;i<maxPlayers;++i){ // loop runs the game by iterating through each player in struct player[] and prompting user for decisions

						int pRow = player[i].pRow;
						int pCol = player[i].pCol;

						puts("\n\n"); // used to format printed information makes it easier for user to read
						puts("\n");

						puts("\n");

						// multiple struct type declarations
						struct slot *foundSlots; // used in find slots function to find near enemies
						struct slot *foundSlotsFar; // used ^ to find far enemies
						struct enemy *foundEnemies; // found enemies struct used for tracking enemies found with scoutPlayer function NOTE see crossops.h line 114 for prototype and scoutPlayer.c for definition
						struct enemyFar *foundEnemiesFar; // same as above
						struct count *nCount; // used to track near enemies found in scout function
						struct count *fCount; // used to track far enemies found in scout function

						foundSlots = calloc(49, sizeof(struct slot )); // allocate memory to struct types which are passed to function. Makes it easy to return value from functions
						foundSlotsFar = calloc(49, sizeof(struct slot ));
						foundEnemies = calloc(49, sizeof(struct enemy));
						foundEnemiesFar = calloc(49, sizeof(struct enemyFar));
						nCount = malloc(sizeof (struct count));
						fCount = malloc(sizeof (struct count));

						// ATTACK FUNCT HERE!!!
						int choice = 0; // used with switch statement

						puts("Would you like to scout for enemies and move(1) or scout for enemies and attack(2)\n");
						scanf("%d%*c",&choice);

						int distChoice = 0; // used with switch statement
						int enemyNcount = 0, enemyFcount = 0;


						switch(choice){ // gives player choice to scout and move or scout and attack

							case 1:

								scoutPlayer(nCount, fCount, &player[i], foundSlots, foundSlotsFar, foundEnemies, foundEnemiesFar, upLeft, upRight, downLeft, downRight); // NOT see crossops.h line 114 for prototype and scoutPlayer.c for definition. Finds near and far enemies to attack

								puts("\n");

								int adjMove = checkAdjSlot(board, pRow, pCol); // see crossops line 113 for prototype. Checks adjacent slots of player current position returns an integer value used in movement function. See checkAdjSlot.c for definition

								puts("\n");

								movement(adjMove, pRow, pCol, i, board, &player[i]); // movement function see crossops.h line 115 for prototype and movement.c for definition. Messy function to move player correctly on board. Takes the return value from slotAdj as an argument value corresponds to how many slots are available to move to e.g. slot(0, 0) only has two possible moves

								
								break;

							case 2: // case two player wants to sout and attack

								scoutPlayer(nCount, fCount, &player[i], foundSlots, foundSlotsFar, foundEnemies, foundEnemiesFar, upLeft, upRight, downLeft, downRight); // see above for explanation

								enemyNcount = nCount->enemyNcount; // nCount is the number of enemies for near attack value is returned from scoutPlayer, see line 64 of scoutPlayer.c each slot that is found within player[i]'s range with a slot.slot_counter == 1 nCount is incremented 1 giving us number of near players
								enemyFcount = fCount->enemyFcount; // same as above see line 89 of scoutPlayer.c

								//printf("EnemiesFcount: %d\nNcount: %d\n",enemyNcount,enemyFcount); // used for debugging checking if values are correct

								if(enemyNcount > 0 && enemyFcount > 0){ // if both values are > 0 the player has enemies close and enemies near they are then given a choice who they want to attack

									puts("You have near and far enemies to attack, enter (1) for near and (2) for far attack\n");
									scanf("%d%*c",&distChoice);
								}
								else if(enemyNcount > 0 && enemyFcount == 0){ // if Ncount value is > 0 and Fcount == 0 then distChoice is set to 1 which is near attack

									distChoice = 1;
								}
								else if(enemyNcount == 0 && enemyFcount > 0){ // same as above but oppsite, Fcount > 0 far attack

									distChoice = 2;
								}

								//printf("\ndistChoice: %d\n",distChoice); // used for debugging tracks correct value is laced in distChoice
								switch(distChoice){ // enter nested  switch statement for attack funtions and decisions

									case 1: // case 1 near attack

										if(enemyNcount == 1){ // if enemy Ncount is 1 there is only one enemy close


												int a = 0;
												int b = enemyNcount + enemyFcount; // value used for gaurd in loop number of enemies both near and far found in scout function

												for(size_t j = 0; j<b;++j){

													if(foundEnemies[j].near_Far == 1){ // redundant code don't have time to remove

														a = foundEnemies[j].enemyTag; // a is stored with enemy tag i.e. player number
													}
												}

												if(player[i].Smartness + player[i].magicSkills > 150){ // magic attack

													magicAttack(&player[i], &player[a]); // magic attack function

													printf("Player[%zd] attacked Player[%d]",i,a);
												}
												else{

													Attack(&player[i], &player[a]); // if player did not meet requirments they attack normal

													printf("Player[%zd] attacked Player[%d]",i,a);
												}
										}
										else{ // else near enemies >  1

											int maxEnemies = enemyNcount + enemyFcount; // value used as gaurd for loop


											for(size_t j = 0; j<maxEnemies;++j){

												if(foundEnemies[j].near_Far == 1){ // finds near enemies in found enemies see line 63 of scoutEnemies.c

													puts("List of nearby enemies\nNumber inside [] is the player tag\n");
													printf("Player[%d](%d, %d)\n",foundEnemies[j].enemyTag,foundEnemies[j].enemyRow,foundEnemies[j].enemyCol); // prints available enemies

													int tagChoice;
													puts("Enter the enemy tag you would like to attack\n");
 													scanf("%d%*c",&tagChoice); // user makes choice who to attack by entering there tag number

													if(player[i].Smartness + player[i].magicSkills > 150){ // magic attack

														magicAttack(&player[i], &player[tagChoice]); // see attack.c for definition

														printf("Player[%zd] attacked Player[%d]",i,tagChoice);
													}
													else{

														Attack(&player[i], &player[tagChoice]); // normal attack if magic is available to player see attack.c

														printf("Player[%zd] attacked Player[%d]",i,tagChoice);
													}
												}
											}
										}
										break;

									case 2: // case two of nested switch exactly the same as above but with far attacks. farAttack definition in Attack.c. all variables found by scoutPlayer function

										if(enemyFcount == 1){


											int a = 0;
											int b = enemyNcount + enemyFcount;

											for(size_t j = 0; j<b;++j){

												if(foundEnemiesFar[j].near_Far == 2){

													a = foundEnemies[j].enemyTag;
												}
											}

											if(player[i].Smartness + player[i].magicSkills > 150){

												magicAttack(&player[i], &player[a]);

												printf("Player[%zd] attacked Player[%d]",i,a);
											}
											else{

												farAttack(&player[i], &player[a]);

												printf("Player[%zd] attacked Player[%d]",i,a);
											}
										}
										else{

											int maxEnemies = enemyNcount + enemyFcount;

											for(size_t j = 0; j<maxEnemies;++j){

												if(foundEnemiesFar[j].near_Far == 2){

													puts("List of nearby enemies\nNumber inside [] is the player tag\n");
													printf("Player[%d](%d, %d)\n",foundEnemies[j].enemyTag,foundEnemies[j].enemyRow,foundEnemies[j].enemyCol);

													int tagChoice;
													puts("Enter the enemy tag you would like to attack\n");
													scanf("%d%*c",&tagChoice);

													if(player[i].Smartness + player[i].magicSkills > 150){

														magicAttack(&player[i], &player[tagChoice]);

														printf("Player[%zd] attacked Player[%d]",i,tagChoice);
													}
													else{

														farAttack(&player[i], &player[tagChoice]);

														printf("Player[%zd] attacked Player[%d]",i,tagChoice);
													}
												}
											}
										}
										break;
								}
								break;
						}
						puts("\n");
			}
			puts("\n\n");
			for(size_t i=0;i<maxPlayers;i++){ // loop prints values after each round

				printf("\n%s (%s, %.1f) position is: (%d, %d) position type: %s\n", player[i].Player_Name, player[i].Player_Type, player[i].lifePoints, player[i].pRow, player[i].pCol, player[i].Current_Pos); // prints current position number and slot type
				

			} // end loop

			//puts("end p"); // used whike debugging making sure program was reaching this point
			scanf("%d%*c",&input); // enter input if 2 continue if < 2 quit

		}while(input > 1);
}

