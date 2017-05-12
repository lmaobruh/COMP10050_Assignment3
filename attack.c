

#include<stdio.h>
#include<stdlib.h>
#include"crossfireOperations.h"

void Attack(struct Player *attacker, struct Player *attacked){ // normal attack
	float a = attacked->Strength;

	if(attacked->Strength <= 70) {
		attacked->lifePoints -= (0.5 * a);
	}
	else if(attacked->Strength > 70)
	{
		attacker->lifePoints -= (0.3 * a);
	}
}

void farAttack(struct Player *attacker, struct Player *attacked) { //far attack

	float a = attacker->Strength;
    float b = attacked->lifePoints;

		if(attacked->Dexterity >= attacker->Dexterity)
		{
			attacked->lifePoints = b;
		}
		else if(attacked->Dexterity < attacker->Dexterity)
		{
			attacked->lifePoints -= (0.3 * a);
		}
}

void magicAttack(struct Player *attacker, struct Player *attacked) { //magic attacks

	float c = attacker->magicSkills;
	float d = attacker->Smartness;

	attacked->lifePoints = (0.5 * c)+(0.2 * d);


}
