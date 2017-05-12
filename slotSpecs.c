/*
 * slotAdj.c
 *
 *  Created on: 13 Apr 2017
 *      Author: richie
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crossfireOperations.h"

char Four[5] = "four", down[3] = "DT", up[3] = "UT", right[3] = "RT", left[3] = "LT", Two[4] = "two"; // used for strcmp with slot char values assigned in slotAdj.c


void slotAdj(struct slot ** board){

	for(size_t i = 1; i<6;i++){ // first loop assigns all slots with 4 possible moves string value four

		for(size_t j = 1; j<6; j++){

			strcpy(board[i][j].adj,Four);
		}
	}

	for(size_t i = 1;i < 6;i++){ // second loop assigns all slots with 3 possible moves different strings depending on there position on the board

		strcpy(board[0][i].adj,down);

		strcpy(board[6][i].adj,up);

		strcpy(board[i][0].adj,right);

		strcpy(board[i][6].adj,left);
	}

	strcpy(board[0][0].adj,Two); // last part assigns four corners with string value two
	strcpy(board[0][6].adj,Two);
	strcpy(board[6][0].adj,Two);
	strcpy(board[6][6].adj,Two);

}


int checkAdjSlot(struct slot **board, int prow, int pcol){ // function prints possible oves to player making it easier to decide where to move
    
    if(strcmp(board[prow][pcol].adj,Four)==0){ // board.adj value assigned in slotAdj.c prints available slots to move to if players current slot has four avaliable slots to moove to
        
        printf("\nYou have four adjacent slots, possible moves are: ");
        printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
        printf("Down (%d, %d, %s), ", prow+1,pcol,board[prow+1][pcol].Slot_Type);
        printf("Left (%d, %d, %s), ",prow,pcol-1,board[prow][pcol-1].Slot_Type);
        printf("Right (%d, %d, %s)",prow,pcol+1,board[prow][pcol+1].Slot_Type);
        
        return 1;
    }
    else if(strcmp(board[prow][pcol].adj,up)==0){ // if player is on the bottom of the board they have three possible moves one being up
        
        printf("\nYou have three adjacent slots, possible moves are: ");
        printf("Up (%d, %d, %s), ", prow-1,pcol,board[prow-1][pcol].Slot_Type);
        printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
        printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
        
        return 2;
    }
    else if(strcmp(board[prow][pcol].adj,down)==0){ // if player is on top of the board with three possible koves
        
        printf("\nYou have three adjacent slots, possible moves are: ");
        printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
        printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
        printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
        
        return 3;
    }
    
    else if(strcmp(board[prow][pcol].adj,left)==0){ // if player is on right hand side with three possible moves
        
        printf("\nYou have three adjacent slots, possible moves are: ");
        printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
        printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
        printf("Down (%d, %d, %s)", prow+1,pcol, board[prow+1][pcol].Slot_Type);
        
        return 4;
    }
    else if(strcmp(board[prow][pcol].adj,right)==0){ // if player is on left hand side of board with three possible moves
        
        printf("\nYou have three adjacent slots, possible moves are: ");
        printf("Up (%d, %d, %s), ", prow-1,pcol, board[prow-1][pcol].Slot_Type);
        printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
        printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
        
        return 5;
    }
    else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 0 && pcol == 0){ // next four staemnets correspond to each corner of the board with two possible moves
        
        printf("\nYou have two adjacent slots, possible moves are: ");
        printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
        printf("Right (%d, %d %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
        
        return 6;
    }
    else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 0 && pcol == 6){
        
        printf("\nYou have two adjacent slots, possible moves are: ");
        printf("Down (%d, %d, %s), ", prow+1,pcol, board[prow+1][pcol].Slot_Type);
        printf("Left (%d, %d, %s)",prow,pcol-1, board[prow][pcol-1].Slot_Type);
        
        return 7;
    }
    else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 6 && pcol == 0){
        
        printf("\nYou have two adjacent slots, possible moves are: ");
        printf("Right (%d, %d, %s)",prow,pcol+1, board[prow][pcol+1].Slot_Type);
        printf("Up (%d, %d, %s)", prow-1,pcol, board[prow-1][pcol].Slot_Type);
        
        return 8;
    }
    else if(strcmp(board[prow][pcol].adj,Two)==0 && prow == 6 && pcol == 6){
        
        printf("\nYou have two adjacent slots, possible moves are: ");
        printf("Left (%d, %d, %s), ",prow,pcol-1, board[prow][pcol-1].Slot_Type);
        printf("Up (%d, %d, %s)", prow-1,pcol, board[prow-1][pcol].Slot_Type);
        
        return 9;
    }
    else
        return 0;
}
