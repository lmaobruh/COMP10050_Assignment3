#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "crossfireOperations.h"
#include "structs.h"


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

			slotAdj(board);

    int playerNumbers;

    do {
        printf("Enter Number of players: ");
        scanf("%d", &playerNumbers);

        if (playerNumbers < 2 || playerNumbers > 6) printf("Players should be between 2 and 6!\n");
    } while(playerNumbers < 2 || playerNumbers > 6);

    struct Player *player = calloc(playerNumbers, sizeof(struct Player));

    for (int i = 0; i < playerNumbers; i++) {
        int playerType = 0;
        printf("Enter Name for Player %d:", i+1);
        scanf("%s", player[i].name);
        printf("Enter Player Type (1 for Ogre, 2 for Elf, 3 for Human, and 4 for Wizard)\n");
        scanf("%d", &playerType);
        if (playerType == 1) OGRE(&player[i]);
        if (playerType == 2) ELF(&player[i]);
        if (playerType == 3) HUMAN(&player[i]);
        if (playerType == 4) WIZARD(&player[i]);
    }

    for (int i = 0; i < playerNumbers; i++) {
        printf("Player %d:\n Name: %s\n",i+1,player[i].name);
        printf("Type: %s\n",player[i].type);
        printf("Life Points: %.1f\n",player[i].lifePoints);
        printf("Dexterity: %d\n",player[i].Dexterity);
        printf("Luck: %d\n",player[i].Luck);
        printf("Magic Skills: %d\n",player[i].magicSkills);
        printf("Smartness: %d\n",player[i].Smartness);
        printf("Strength: %d\n",player[i].Strength);
        printf("\n\n");
    }

    for(int i=0;i<playerNumbers;i++) { // this loop assigns a random slot to all the players
		slotAssign(&player[i]);
        int slotRow, slotColm;

        slotRow = player[i].slotRow;
        slotColm = player[i].slotColm;
        printf("Player %s is in the slot(%d, %d) with type: %s\n",player[i].name, board[slotRow][slotColm].row, board[slotRow][slotColm].column, board[slotRow][slotColm].slotType);
        strcpy(player[i].currentPosition,board[slotRow][slotColm].slotType);


	}

printf("\n******************************************\n\nGAME START\n");

int input = 0;
	do{

		for(size_t i = 0;i<playerNumbers;++i) {

					int slotRow = player[i].slotRow;
					int slotColm = player[i].slotColm;

					// multiple struct type declarations
					struct slot *enemyPosNear;
					struct slot *enemyPosFar;
					struct enemy *enemyPosLock;
					struct enemyFar *enemyPosLockFar;
					struct count *near;
					struct count *far;

					enemyPosNear = calloc(49, sizeof(struct slot ));
					enemyPosFar = calloc(49, sizeof(struct slot ));
					enemyPosLock = calloc(49, sizeof(struct enemy));
					enemyPosLockFar = calloc(49, sizeof(struct enemyFar));
					near = malloc(sizeof (struct count));
					far = malloc(sizeof (struct count));


					int choice = 0;

					puts("Enter 1 to Move and 2 to Attack!\n");
					scanf("%d",&choice);

					int attackChoice = 0;
					int enemynear = 0, enemyfar = 0;


					switch(choice){

						case 1: //Player wants to move

							scoutPlayer(near, far, &player[i], enemyPosNear, enemyPosFar, enemyPosLock, enemyPosLockFar, upLeft, upRight, downLeft, downRight);
							puts("\n");

							gameturn(slotRow, slotColm, i, board, &player[i]);


							break;

						case 2: // Player wants to attack

							scoutPlayer(near, far, &player[i], enemyPosNear, enemyPosFar, enemyPosLock, enemyPosLockFar, upLeft, upRight, downLeft, downRight); // see above for explanation

							enemynear = near->enemynear;
							enemyfar = far->enemyfar;



							if(enemynear > 0 && enemyfar > 0){

								puts("Enter 1 to Attack Near Enemy and 2 to Attack Far enemy\n");
								scanf("%d%*c",&attackChoice);
							}
							else if(enemynear > 0 && enemyfar == 0){

								attackChoice = 1;
							}
							else if(enemynear == 0 && enemyfar > 0){

								attackChoice = 2;
							}

							switch(attackChoice){

								case 1: // near attack

										int totalEnemies = enemynear + enemyfar;

										for(size_t j = 0; j<totalEnemies;++j){

											if(enemyPosLock[j].near_Far == 1){

												puts("Choose from serial number to enemies nearby:\n");
												printf("Player no. %d who is at (%d, %d)\n",enemyPosLock[j].enemyTag,enemyPosLock[j].enemyRow,enemyPosLock[j].enemyCol); // prints available enemies

												int serialNumber;
												puts("Enter the enemy number you wish to attack\n");
												scanf("%d%*c",&serialNumber);

												if(player[i].Smartness + player[i].magicSkills > 150){ // magic attack

													magicAttack(&player[i], &player[serialNumber]);

													printf("Player[%zd] attacked Player[%d]",i,serialNumber);
												}
												else{

													Attack(&player[i], &player[serialNumber]);

													printf("Player[%zd] attacked Player[%d]",i,serialNumber);
												}
											}
										}

									break;

								case 2: {

										int totalEnemies = enemynear + enemyfar;

										for(size_t j = 0; j<totalEnemies;++j){

											if(enemyPosLockFar[j].near_Far == 2){

												puts("Choose from serial number of following enemies:\n");
												printf("Player no. %d who is at (%d, %d)\n",enemyPosLock[j].enemyTag,enemyPosLock[j].enemyRow,enemyPosLock[j].enemyCol);

												int serialNumber;
												puts("Enter enemy number you wish to attack\n");
												scanf("%d%*c",&serialNumber);

												if(player[i].Smartness + player[i].magicSkills > 150){

													magicAttack(&player[i], &player[serialNumber]);

													printf("Player[%zd] attacked Player[%d]",i,serialNumber);
												}
												else{

													farAttack(&player[i], &player[serialNumber]);

													printf("Player[%zd] attacked Player[%d]",i,serialNumber);
												}
											}
										}
									}
									break;
							}
							break;
					}
		}
		puts("\n\n");
		for(int i=0;i<playerNumbers;i++){

			printf("\n%s (%s, %.1f) position is: (%d, %d) position type: %s\n", player[i].name, player[i].type, player[i].lifePoints, player[i].slotRow, player[i].slotColm, player[i].currentPosition); // prints current position number and slot type

		} // end loop


		scanf("%d%*c",&input); // enter input if 2 continue if < 2 quit

	}while(input > 1);



}
