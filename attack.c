

#include<stdio.h>
#include<stdlib.h>
#include"crossfireOperations.h"

void Attack(struct Player *attacker, struct Player *attacked){
	float St = attacked->Strength;	//float to hold the value of the attacked players strength.

	if(attacked->Strength <= 70)		//If the attacked players strength is less than or equal to 70 then the attacked player gets half of there strength taken
	{
		attacked->lifePoints -= (0.5 * St);
	}
	else if(attacked->Strength > 70)	//If the attacked players strength is greater than 70 then the player who initiated the attack gets 0.3 of the attacked players strength taken from their life points.
	{
		attacker->lifePoints -= (0.3 * St);
	}
}

void farAttack(struct Player *attacker, struct Player *attacked){

	float St = attacker->Strength;	//float to hold the value of the attacker players strength.
	float Lp = attacked->lifePoints; // store attacked players life points

		if(attacked->Dexterity >= attacker->Dexterity) // modifies on certain condition given with assignment
		{
			attacked->lifePoints = Lp;
		}
		else if(attacked->Dexterity < attacker->Dexterity)
		{
			attacked->lifePoints -= (0.3 * St);
		}
}

void magicAttack(struct Player *attacker, struct Player *attacked){

	float Mag = attacker->magicSkills;	//float to hold the value of the attacker players magic skill.
	float Sm = attacker->Smartness; //float to hold the value of the attacker players smartness skill.

	attacked->lifePoints = (0.5 * Mag)+(0.2 * Sm);


}
