

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crossfireOperations.h"

extern char Hill[5],Ground[7],City[5]; // extern chars used to assign slot types

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot ** board){


	for(int i =0; i< boardSize; i++){
		//This allocates in memory the space for the slots in each row of the board
		board[i] = malloc(boardSize * sizeof(struct slot));

		//For each slot it sets up the row and column number
		for(int j=0;j < boardSize; j++){
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	//It sets up the adjacent slots for the slots that are
	//not at the borders. These slots have 4 adjacent elements
	for(int i =1; i< boardSize-1; i++){
		for(int j=1;j < boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			board[i][j].right = &board[i][j+1];
			board[i][j].down = &board[i+1][j];
			board[i][j].left = &board[i][j-1];
		}
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last row, except the slots at the edges.
	//
	for(int j = 1; j < boardSize -1; j++){
		//It sets up the adjacent slots for the slots that are in the first row.
		//These slots don't have an adjacent element on top of them
		// because they are on the first row of the board
		board[0][j].right = &board[0][j+1];
		board[0][j].left = &board[0][j-1];
		board[0][j].down = &board[1][j];
		board[0][j].up = NULL;

		//It sets up the adjacent slots for the slots that are in the last row.
		//These slots don't have an adjacent element on down them
		// because they are on the last row of the board
		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
		board[boardSize - 1][j].down = NULL;
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last column, except the slots at the edges.
	//
	for(int i = 1; i < boardSize -1; i++){
		//It sets up the adjacent slots for the slots that are in the first column.
		//These slots don't have an adjacent element on the left
		// because they are on the first column of the board
		board[i][0].right = &board[i][1];
		board[i][0].up = &board[i-1][0];
		board[i][0].down = &board[i+1][0];
		board[i][0].left = NULL;

		//It sets up the adjacent slots for the slots that are in the last column.
		//These slots don't have an adjacent element on the right
		// because they are on the last column of the board
		board[i][boardSize-1].left = &board[i][boardSize-2];
		board[i][boardSize -1].up = &board[i -1][boardSize-1];
		board[i][boardSize -1].down = &board[i+1][boardSize -1];
		board[i][boardSize -1].right = NULL;
	}


		//It sets up the adjacent slots for the slot at position (0,0).
		//This only has only 2 adjacent slots: right and down
		board[0][0].right = &board[0][1];
		board[0][0].down = &board[1][0];

		//It sets up the adjacent slots for the slot at position (0,boardSize -1).
		//This only has only 2 adjacent slots: left and down
		board[0][boardSize-1].left = &board[0][boardSize-2];
		board[0][boardSize -1].down = &board[1][boardSize -1];

		//It sets up the adjacent slots for the slot at position (boarSize -1 ,0).
		//This only has only 2 adjacent slots: up and right
		board[boardSize -1][0].right = &board[boardSize -1][1];
		board[boardSize -1][0].up = &board[boardSize -2][0];

		//It sets up the adjacent slots for the slot at position (boarSize -1 ,boardSize-1).
		//This only has only 2 adjacent slots: up and left
		board[boardSize - 1][boardSize-1].up = &board[boardSize-2][boardSize-1];
		board[boardSize - 1][boardSize -1].left = &board[boardSize -1][boardSize -2];







	//assigns a pointer to slot at position (0, 0)
	*upLeft = &board[0][0];
	//assigns pointer of pointer to slot at position (0, boardSize -1)
	*upRight = &board[0][boardSize -1];
	//assigns pointer of pointer to slot at position ( boardSize -1,)
	*downLeft = &board[boardSize -1][0];
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	*downRight = &board[boardSize -1][boardSize -1];

	for(int i =0; i< boardSize; i++){

			//For each slot it sets up the row and column number
			for(int j=0;j < boardSize; j++){

				board[i][j].Slot_Tag = -1;
				board[i][j].counter = 0;

				int max=4,min=1; // initialise three random numbers with min value 1 and max 10000. max random high to lower chance of equal numbers
				int rng = rand()%(max-min)+min;


				if(rng == 1){ // if rng is greater than rng1 and rng2 slot[i].Slot_Type will get assigned city type.

					strcpy(board[i][j].Slot_Type,City);
				}
				else if(rng == 2){ // same as above except rng1 and Ground will be assigned

					strcpy(board[i][j].Slot_Type,Ground);
				}
				else if(rng == 3){ // same except rng2 and Hill will be assigned

					strcpy(board[i][j].Slot_Type,Hill);
				}
			}
		}
	}

struct slot * reachDesiredElement(int row, int column, struct slot * initialSlot){

	bool found = false;

	struct slot * currentSlot = initialSlot;

	//printf("Initial slot (%d, %d) -> \n",initialSlot->row,initialSlot->column);


	while(found == false){


		if(currentSlot->row > row){

			currentSlot = currentSlot->up;

			//printf("Current slot (%d, %d, %s) -> \n",currentSlot->row,currentSlot->column,currentSlot->Slot_Type);
		}

		if(currentSlot->row < row){

			currentSlot = currentSlot->down;

			//printf("Current slot (%d, %d, %s) -> \n",currentSlot->row,currentSlot->column,currentSlot->Slot_Type);

		}

		if(currentSlot->column > column){

			currentSlot = currentSlot->left;

			//printf("Current slot (%d, %d, %s) -> \n",currentSlot->row,currentSlot->column,currentSlot->Slot_Type);
		}

		if(currentSlot->column < column){

			currentSlot = currentSlot->right;

			//printf("Current slot (%d, %d, %s) -> \n",currentSlot->row,currentSlot->column,currentSlot->Slot_Type);

		}

		if(currentSlot->column == column && currentSlot->row == row){
			//printf("Found\n");
			found = true;

		}

	}

	return currentSlot;
}

void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[BOARD_SIZE][BOARD_SIZE]){

	//The base case: the current slot is at the required distance from the starting slot
	if(currDist == reqDist){
		//the current slot was not explored
		if(explored[currSlot->row][currSlot->column] == false){
			//The next availbale position (indicated by count) at foundSlots points to the current slot
			*(foundSlots + *count) = *currSlot;
			//the counter is incremented
			(*count)++;
			//the matrix of the explored slots set to true the element at the row and column of the current slot
			explored[currSlot->row][currSlot->column] = true;
		}
	}
	//The recursive call: the current slot is at a distance that is less than the required distance (more slots still have to be traversed)
	else{
		//if the current slot has the up slot != NULL (i.e. the slot is not in the first row)
		if(currSlot->up != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the up slot
			findSlots(reqDist, currDist +1,  currSlot->up, foundSlots, count, explored);
		}
		//if the current slot has the right slot != NULL (i.e. the slot is not in the last column)
		if(currSlot->right != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the right slot
			findSlots(reqDist, currDist +1,  currSlot->right, foundSlots, count, explored);
		}
		//if the current slot has the down slot != NULL (i.e. the slot is not in the last row)
		if(currSlot->down != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the down slot
			findSlots(reqDist, currDist +1,  currSlot->down, foundSlots, count, explored);
		}
		//if the current slot has the left slot != NULL (i.e. the slot is not in the first column)
		if(currSlot->left != NULL){
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the left slot
			findSlots(reqDist, currDist +1,  currSlot->left, foundSlots, count, explored);
		}

	}


}
