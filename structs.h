#ifndef STRUCTS_H_
#define STRUCTS_H_

struct Player{

		char name[50];
		char type[50];
		char currentPosition[7]; // is assigned slot type for player
		float lifePoints; // is assigned 100 for player life points
		int Smartness; // is assigned a value depending on player.Player_Type.
		int Strength; // see ^
		int magicSkills; // see ^
		int Luck; // see ^
		int Dexterity; // see ^
		int slotRow;
		int slotColm;
};

struct count{

	int enemyNcount;
	int enemyFcount;
};

struct enemy{

	int enemyRow;
	int enemyCol;
	int enemyTag;
	int near_Far;

};
struct enemyFar{

	int enemyRow;
	int enemyCol;
	int enemyTag;
	int near_Far;

};

struct slot{
	//row number
	int row;
	//column number
	int column;

	// adjacent left slot
	struct slot *left;
	// adjacent right slot
	struct slot *right;
	// adjacent up slot
	struct slot *up;
	// adjacent down slot
	struct slot *down;

	char slotType[7]; // is assigned a slot type randomly e.g. slot.slotType = "City"

	int slotCurrPlay; // used to keep track of who is in what slot

	int occ; // occ used to keep track of if a slot is occupied

	char adj[5]; // slots with adjacency of 4

}slot;

#endif
