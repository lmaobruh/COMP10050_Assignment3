/* Includes specifications for assigning points to players */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"crossfireOperations.h"

char str[5]="Ogre",str2[4]="Elf",str3[6]="Human",str4[7]="Wizard",str5[5]="ogre",str6[4]="elf",str7[6]="human",str8[7]="wizard"; // Used in AssignType function NOTE: see line 114

void AssignType(struct Player *player){ // Assigns type to player depending on type picked by player
    
    if(strcmp(player->Player_Type,str)==0 || strcmp(player->Player_Type,str5)==0){
        
        OGRE(player);
    }
    else if(strcmp(player->Player_Type,str2)==0 || strcmp(player->Player_Type,str6)==0){ // if player is elf
        
        ELF(player);
    }
    else if(strcmp(player->Player_Type,str3)==0 || strcmp(player->Player_Type,str7)==0){
        
        do{ // repeats HUMAN function if sum of capabilities is greater than 300
            HUMAN(player);
            printf("\n");
        }while(player->Dexterity + player->Luck + player->magicSkills + player->Smartness + player->Strength > 300);
    }
    else if(strcmp(player->Player_Type,str4)==0 || strcmp(player->Player_Type,str8) ==0){
        
        WIZARD(player);
    }
}


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


void ModStr(struct Player *player){ // modifies capabilities based on rules of game
    
    if(player->Dexterity <50){
        
        player->Strength -= 10;
    }
    else if(player->Dexterity >=60){
        
        player->Strength += 10;
    }
}
void ModMag(struct Player *player){ // same  as above^
    
    if(player->Smartness > 60){
        
        player->magicSkills += 10;
    }
    else if(player->Smartness<=50){
        
        player->magicSkills -= 10;
    }
}


void ReverseModStr(struct Player *player){ // reverts capabilities used to stop capability stacking
    
    if(player->Dexterity <50){
        
        player->Strength += 10;
    }
    else if(player->Dexterity >=60){
        
        player->Strength -= 10;
    }
}
void ReverseModMag(struct Player *player){ // same as above ^
    
    if(player->Smartness > 60){
        
        player->magicSkills -= 10;
    }
    else if(player->Smartness<=50){
        
        player->magicSkills += 10;
    }
}
