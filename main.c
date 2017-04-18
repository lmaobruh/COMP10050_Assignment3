#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"



int main(){

	int row, column;

	struct slot* currSlot = NULL;
	struct slot *foundSlots;
	bool explored[BOARD_SIZE][BOARD_SIZE];
	int count =0;

	//pointer to slot (1,1)
	struct slot *upLeft;

	//pointer to slot (1,7)
	struct slot *upRight;

	//pointer to slot (7,1)
	struct slot *downLeft;

	//pointer to slot (7, 7)
	struct slot *downRight;


	//Creates the board
	createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight);

	/*	Asks the user the row and the column of the slot
		s/he wants to retrieve from the board.
		Note that the user needs to know the size of the board to input
		the correct row and column of the slot s/he wants to retrieve */
	getDesiredElement(BOARD_SIZE, &row,&column);

	//Finds the slot


	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (7, 7)*/
	if(row >= BOARD_SIZE/2){
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column,downRight);
		else
		/*If the the required slot is closer to the down-left
		* corner of the board the search starts from downLeft,
		* which points to slot at position (boardSize, 1)*/
			currSlot = reachDesiredElement(row,column,downLeft);
	} else {
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (1,7)*/
		if(column >= BOARD_SIZE/2)
			currSlot = reachDesiredElement(row,column, upRight);
		/*If the the required slot is closer to the up-left
		* corner of the board the search starts from upLeft,
		* which points to slot at position (1, 1)*/
		else currSlot = reachDesiredElement(row,column,upLeft);
	}

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}

	foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
	printf("\n\nThese are the slots you can move to in your next turn\n");

	if(currSlot!= NULL){
		//invokes function findSlots. The required distance is a constant
		//However you can reuse this function providing as input any arbitrary distance
		findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
		for(int i=0; i<count; i++){
			printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
		}
	}

	return 0;
}
