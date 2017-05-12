
#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"

struct slot* currSlot = NULL;

bool explored[BOARD_SIZE][BOARD_SIZE];
int count =0;
int near = 1;
int far = 5;
void scoutPlayer(struct count *nCount, struct count *fCount,struct Player *player,struct slot *foundSlots, struct slot *foundSlotsFar, struct enemy *foundEnemies, struct enemyFar *foundEnemiesFar, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight){


	int row = player->pRow;
	int column = player->pCol;

	//code is taken from lilliana's main function

	if(row >= BOARD_SIZE/2){
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column,downRight);
		else

			currSlot = reachDesiredElement(row,column,downLeft);
	} else {

		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column, upRight);

		else currSlot = reachDesiredElement(row,column,upLeft);
	}

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}

	if(currSlot!= NULL){


			count = 0; // initialize count to 0 on every function call. Errors occurring with count stacking on each function call eventually going beyond memory bounds of foundSlots causing errors. Took a day to find this bug :(

			findSlots(near, 0, currSlot, foundSlots, &count, explored); // using ffindslots function to find near slots to attack

			//printf("\nCOUNT: %d\n",count);// was used to find bug in this function ^ above for details

			for(size_t i=0; i<count; ++i){


				if(foundSlots[i].counter == 1){ // if counter is == 1 there is a player present on this slot

					printf("\nEnemy found for near attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlots[i].row, foundSlots[i].column, foundSlots[i].Slot_Tag);
					fflush(stdout);

					foundEnemies[i].enemyRow = foundSlots[i].row; // stores information fused in attack sequence
					foundEnemies[i].enemyCol = foundSlots[i].column;
					foundEnemies[i].enemyTag = foundSlots[i].Slot_Tag;
					foundEnemies[i].near_Far = 1;
					nCount->enemyNcount += 1; // counts enemies found near

					//used in debugging printf("foundEnemies %d %d %d %d %d\n",foundEnemies[i].enemyRow, foundEnemies[i].enemyCol, foundEnemies[i].enemyTag, foundEnemies[i].near_Far, nCount->enemyNcount);
					fflush(stdout);
				}
			}

			count = 0; // initialize count to 0 on every function call. Errors occurring with count stacking on each function call eventually going beyond memory bounds of foundSlots causing errors. Took a day to find this bug :(

			findSlots(far, 1, currSlot, foundSlotsFar, &count, explored);

			printf("\nCOUNT: %d\n",count);// was used to find bug in this function ^ above for details

			for(size_t i=0; i<count; ++i){


				if(foundSlotsFar[i].counter == 1 && foundSlotsFar[i].row != row && foundSlotsFar[i].column != column && (foundSlotsFar[i].row > row+1 || foundSlotsFar[i].column < row-1 || foundSlotsFar[i].column > column+1 || foundSlotsFar[i].column < column-1)){

					printf("\nEnemy found for far attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlotsFar[i].row, foundSlotsFar[i].column, foundSlotsFar[i].Slot_Tag);
					fflush(stdout);

					//same as above except far enmies are tracked and information used in attack sequence
					foundEnemiesFar[i].enemyRow = foundSlotsFar[i].row;
					foundEnemiesFar[i].enemyCol = foundSlotsFar[i].column;
					foundEnemiesFar[i].enemyTag = foundSlotsFar[i].Slot_Tag;
					foundEnemiesFar[i].near_Far = 2;
					fCount->enemyFcount += 1;

					printf("foundEnemies %d %d %d %d %d\n",foundEnemiesFar[i].enemyRow, foundEnemiesFar[i].enemyCol, foundEnemiesFar[i].enemyTag, foundEnemiesFar[i].near_Far, fCount->enemyFcount);
					fflush(stdout);
				}
			}
	}
}
