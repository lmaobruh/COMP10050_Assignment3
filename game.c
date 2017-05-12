

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"crossfireOperations.h"

char UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd';

extern char Hill[5], City[5];

void movement(int move,  int row, int column, int pnum, struct slot **board, struct Player *player){

	char walk;

	// Enormous function usd to move players on board. Most of the code is very similar I had planned on coming back to and shortening it down using functions but ran out of time

	if(move == 1){

		printf("Press 'w' = up, 's' = down, 'a' = left, 'd' = right");
		scanf("%c%*c",&walk); // "%c%*c" Used throughout the program to flush the input buffer. I was having trouble with \n charcters being stuck in the input buffer took me ages to figure it out

		if(walk == UP){;


			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow -= 1; // if movement up row decrements 1
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type); // player is assigned new slot type

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE: See CrossFunct.c line 16 for function definition.
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE: See CrossFunct.c line 27 for function definition.
			}

			board[row][column].Slot_Tag = -1; // previous slot values are returned to normal
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum; // new slot values are updated
			board[row-1][column].counter = 1;

			// NOTE: function bsically is the same as above except for direction of movement
		}
		else if(walk == DOWN){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 2){

		printf("Press 'w' = up, 'a' = left, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 3){

		printf("Press 's' = down, 'a' = left, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == DOWN){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 4){

		printf("Press 'w' = up, 'a' = left, 's' = down\n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == DOWN){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = pnum;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
	}

	else if(move == 5){

		printf("Press 'w' = up, 'a' = left, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == UP){;

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
		else if(walk == RIGHT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 6){

		printf("Press 's' = down, 'd' = right\n");
		scanf("%c%*c",&walk);

		if(walk == DOWN){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == RIGHT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 7){

		printf("Press 's' = down, 'a' = left\n");
		scanf("%c%*c",&walk);

		if(walk == DOWN){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same ^

			player->pRow += 1;
			strcpy(player->Current_Pos,board[row+1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row+1][column].Slot_Tag = pnum;
			board[row+1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
	}

	else if(move == 8){

		printf("Press 'w' = up, 'd' = right, \n");
		scanf("%c%*c",&walk);

		if(walk == UP){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == RIGHT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same

			player->pCol += 1;
			strcpy(player->Current_Pos,board[row][column+1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column+1].Slot_Tag = pnum;
			board[row][column+1].counter = 1;

		}
	}

	else if(move == 9){

		printf("Press 'w' = up, 'a' = left, \n");
		scanf("%c%*c",&walk);

		if(walk == UP){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same

			player->pRow -= 1;
			strcpy(player->Current_Pos,board[row-1][column].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row-1][column].Slot_Tag = pnum;
			board[row-1][column].counter = 1;

		}
		else if(walk == LEFT){

			ReverseModStr(player); // reverse capability mod for strength before player moves to new slot ensures capabilites modification based on slot type does not stack
			ReverseModMag(player); // same

			player->pCol -= 1;
			strcpy(player->Current_Pos,board[row][column-1].Slot_Type);

			if(strcmp(player->Current_Pos,Hill)==0){ // compares current position to char array Hill if 0 modify strength according to game rules

				ModStr(player); // calls ModStr function NOTE:
			}
			else if(strcmp(player->Current_Pos,City)==0){ // same ^

				ModMag(player); // calls ModMag function NOTE:
			}

			board[row][column].Slot_Tag = -1;
			board[row][column].counter = 0;

			board[row][column-1].Slot_Tag = pnum;
			board[row][column-1].counter = 1;

		}
	}
}
