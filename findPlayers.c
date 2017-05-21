
#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"
#include "structs.h"

struct slot* currSlot = NULL;

bool explored[BOARD_SIZE][BOARD_SIZE];
int count =0;
int near = 1;
int far = 5;

void scoutPlayer(struct count *nCount, struct count *fCount,struct Player *player,struct slot *foundSlots, struct slot *foundSlotsFar, struct enemy *foundEnemies, struct enemyFar *foundEnemiesFar, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight){


	int row = player->slotRow;
	int column = player->slotColm;

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


			count = 0;

			findSlots(near, 0, currSlot, foundSlots, &count, explored);

			for(size_t i=0; i<count; ++i){


				if(foundSlots[i].occ == 1){ // if occ is == 1 there is a player present on this slot

					printf("\nEnemy found for near attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlots[i].row, foundSlots[i].column, foundSlots[i].slotCurrPlay);
					fflush(stdout);

					foundEnemies[i].enemyRow = foundSlots[i].row; // stores information fused in attack sequence
					foundEnemies[i].enemyCol = foundSlots[i].column;
					foundEnemies[i].enemyTag = foundSlots[i].slotCurrPlay;
					foundEnemies[i].near_Far = 1;
					nCount->enemyNcount += 1; // counts enemies found near

					fflush(stdout);
				}
			}

			count = 0;

			findSlots(far, 1, currSlot, foundSlotsFar, &count, explored);

			printf("\nCOUNT: %d\n",count);

			for(size_t i=0; i<count; ++i){


				if(foundSlotsFar[i].occ == 1 && foundSlotsFar[i].row != row && foundSlotsFar[i].column != column && (foundSlotsFar[i].row > row+1 || foundSlotsFar[i].column < row-1 || foundSlotsFar[i].column > column+1 || foundSlotsFar[i].column < column-1)){

					printf("\nEnemy found for far attack\nLocation: (%d, %d)\nEnemy: player[%d]\n", foundSlotsFar[i].row, foundSlotsFar[i].column, foundSlotsFar[i].slotCurrPlay);
					fflush(stdout);

					//same as above except far enmies are tracked and information used in attack sequence
					foundEnemiesFar[i].enemyRow = foundSlotsFar[i].row;
					foundEnemiesFar[i].enemyCol = foundSlotsFar[i].column;
					foundEnemiesFar[i].enemyTag = foundSlotsFar[i].slotCurrPlay;
					foundEnemiesFar[i].near_Far = 2;
					fCount->enemyFcount += 1;

					printf("foundEnemies %d %d %d %d %d\n",foundEnemiesFar[i].enemyRow, foundEnemiesFar[i].enemyCol, foundEnemiesFar[i].enemyTag, foundEnemiesFar[i].near_Far, fCount->enemyFcount);
					fflush(stdout);
				}
			}
	}
}
