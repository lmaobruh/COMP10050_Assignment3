

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"crossfireOperations.h"
#include "structs.h"


void gameturn(int row, int column, int pnum, struct slot **board, struct Player *player) {

	char walk;
	char UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd';

		printf("Video Game Controls! Press 'w' for up, 's' for down, 'a' for left, & 'd' for right!");
		scanf("%c%*c",&walk);

		if(walk == UP) {

			UndoModCity(player);
			UndoModHill(player);

			player->slotRow -= 1;
			strcpy(player->currentPosition,board[row-1][column].slotType);

			if(strcmp(player->currentPosition,"Hill")==0){

				modCity(player);
			}
			else if(strcmp(player->currentPosition,"City")==0){

				modHill(player);
			}

			board[row][column].slotCurrPlay = -1;
			board[row][column].occ = 0;

			board[row-1][column].slotCurrPlay = pnum;
			board[row-1][column].occ = 1;

		}
		else if(walk == DOWN){

			UndoModCity(player);
			UndoModHill(player);

			player->slotRow += 1;
			strcpy(player->currentPosition,board[row+1][column].slotType);

			if(strcmp(player->currentPosition,"Hill")==0){

				modCity(player);
			}
			else if(strcmp(player->currentPosition,"City")==0){

				modHill(player);
			}

			board[row][column].slotCurrPlay = -1;
			board[row][column].occ = 0;

			board[row+1][column].slotCurrPlay = pnum;
			board[row+1][column].occ = 1;

		}
		else if(walk == LEFT){

			UndoModCity(player);
			UndoModHill(player);

			player->slotColm -= 1;
			strcpy(player->currentPosition,board[row][column-1].slotType);

			if(strcmp(player->currentPosition,"Hill")==0){

				modCity(player);
			}
			else if(strcmp(player->currentPosition,"City")==0){ // same ^

				modHill(player);
			}

			board[row][column].slotCurrPlay = -1;
			board[row][column].occ = 0;

			board[row][column-1].slotCurrPlay = pnum;
			board[row][column-1].occ = 1;

		}
		else if(walk == RIGHT){

			UndoModCity(player);
			UndoModHill(player);

			player->slotColm += 1;
			strcpy(player->currentPosition,board[row][column+1].slotType);

			if(strcmp(player->currentPosition,"Hill")==0){

				modCity(player);
			}
			else if(strcmp(player->currentPosition,"City")==0){

				modHill(player); 
			}

			board[row][column].slotCurrPlay = -1;
			board[row][column].occ = 0;

			board[row][column+1].slotCurrPlay = pnum;
			board[row][column+1].occ = 1;

		}
	}

}
