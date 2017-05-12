

#ifndef CROSSOPS_H_
#define CROSSOPS_H_

#define BOARD_SIZE 7
#define REQ_DISTANCE 3


/*
 * The slot template
 */

struct Player{

		char Player_Name[50];
		char Player_Type[50];
		char Current_Pos[7]; // is assigned slot type for player
		float lifePoints; // is assigned 100 for player life points
		int Smartness; // is assigned a value depending on player.Player_Type.
		int Strength; // see ^
		int magicSkills; // see ^
		int Luck; // see ^
		int Dexterity; // see ^
		int pRow;
		int pCol;
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

	char Slot_Type[7]; // is assigned a slot type randomly e.g. slot.Slot_Type = "City"

	int Slot_Tag; // used to keep track of who is in what slot

	int counter; // counter used to keep track of if a slot is occupied

	char adj[5]; // slots with adjacency of 4

}slot;


int getBoardSize();

void getDesiredElement(int maxsize, int * row, int * col);

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot **board);


struct slot *  reachDesiredElement(int row, int column, struct slot * initialSlot);


void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[7][7]);
void ELF(struct Player *player);
void WIZARD(struct Player *player);
void HUMAN(struct Player *player);
void OGRE(struct Player *player);
void AssignType(struct Player *player);
void ModStr(struct Player *player);
void ModMag(struct Player *player);
void ReverseModStr(struct Player *player);
void ReverseModMag(struct Player *player);
void Attack(struct Player *attacker,struct Player *attacked);
void farAttack(struct Player *attacker, struct Player *attacked);
void magicAttack(struct Player *attacker, struct Player *attacked);
void slotAdj(struct slot ** board);
int checkAdjSlot(struct slot **board, int prow, int pcol);
void scoutPlayer(struct count *nCount, struct count *fCount, struct Player *player, struct slot *foundSLots, struct slot *foundSlotsFar, struct enemy *foundEnemies, struct enemyFar *foundEnemiesFar, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight);
void movement(int move, int row, int column, int pnum, struct slot **board, struct Player *player);
#endif /* CROSSOPS_H_ */
