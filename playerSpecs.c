/* Includes specifications for assigning points to players */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"crossfireOperations.h"
#include "structs.h"


void ELF(struct Player *player) { // For Elf type

	int a=101,b=60,c=51,d=80,e=70,f=101;
	int i = rand()%101 + 1;
	int j = rand()%(a-b)+b;
	int m = rand()%(d-c)+c;
	int k = rand()%(f-e)+e;
	int l = rand()%51 + 1;

	player->lifePoints = 100.0;
	player->Dexterity = i;
	player->Luck = j;
	player->magicSkills = m;
	player->Smartness = k;
	player->Strength = l;

}

void WIZARD(struct Player *player) { // For Wizard type

	int c=80,d=101,g=50,h=101;

	int i = rand()%100 + 1;
	int j = rand()%(h-g)+g;
	int m = rand()%(d-c)+c;
	int k = rand()%100 + 1;
	int l = rand()%20 + 1;

	player->lifePoints = 100.0;
	player->Dexterity=i;
	player->Luck=j;
	player->magicSkills=m;
	player->Smartness=k;
	player->Strength=l;
}

void HUMAN(struct Player *player) {


		int i = rand()%101 + 1;
		int j = rand()%101 + 1;
		int m = rand()%101 + 1;
		int k = rand()%101 + 1;
		int l = rand()%101 + 1;

		int sum = i+j+m+k+l;

		player->lifePoints = 100.0;
		player->Dexterity=i;
		player->Luck=j;
		player->magicSkills=m;
		player->Smartness=k;
		player->Strength=l;

}

void OGRE(struct Player *player) { // For Ogre Type

	int a=101,b=80;
	int i = rand()%(a-b)+b;
	int j = rand()%31 + 1;
	int k = rand()%21 + 1;
	int l = rand()%(a-b)+b;

	player->lifePoints = 100.0;
	player->Dexterity = i;
	player->Luck = j;
	player->magicSkills = 0;
	player->Smartness = k;
	player->Strength = l;
}


void modHill(struct Player *player){ // modifies capabilities based on rules of game

    if(player->Dexterity <50){

        player->Strength -= 10;
    }
    else if(player->Dexterity >=60){

        player->Strength += 10;
    }
}
void modCity(struct Player *player){ // same  as above^

    if(player->Smartness > 60){

        player->magicSkills += 10;
    }
    else if(player->Smartness<=50){

        player->magicSkills -= 10;
    }
}


void UndoModHill(struct Player *player){ // reverts capabilities used to stop capability stacking

    if(player->Dexterity <50){

        player->Strength += 10;
    }
    else if(player->Dexterity >=60){

        player->Strength -= 10;
    }
}
void UndoModCity(struct Player *player){ // same as above ^

    if(player->Smartness > 60){

        player->magicSkills -= 10;
    }
    else if(player->Smartness<=50){

        player->magicSkills += 10;
    }
}
