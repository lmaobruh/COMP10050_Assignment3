

#ifndef CROSSFIREOPERATIONS_H_
#define CROSSFIREOPERATIONS_H_

#define BOARD_SIZE 7
#define REQ_DISTANCE 3

typedef int bool;
enum{false, true};

int getBoardSize();

void getDesiredElement(int maxsize, int * row, int * col);

void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot **board);

struct slot *  reachDesiredElement(int row, int column, struct slot * initialSlot);

void slotAssign(struct Player *player);

void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  int explored[7][7]);

void ELF(struct Player *player);

void WIZARD(struct Player *player);

void HUMAN(struct Player *player);

void OGRE(struct Player *player);

void modHill(struct Player *player);

void modCity(struct Player *player);

void UndoModHill(struct Player *player);

void UndoModCity(struct Player *player);

void Attack(struct Player *attacker,struct Player *attacked);

void farAttack(struct Player *attacker, struct Player *attacked);

void magicAttack(struct Player *attacker, struct Player *attacked);

void slotAdj(struct slot ** board);

int checkAdjSlot(struct slot **board, int slotRow, int slotColm);

void scoutPlayer(struct count *nCount, struct count *fCount, struct Player *player, struct slot *foundSLots, struct slot *foundSlotsFar, struct enemy *foundEnemies, struct enemyFar *foundEnemiesFar, struct slot * upLeft, struct slot * upRight, struct slot * downLeft, struct slot * downRight);

void gameturn(int row, int column, int pnum, struct slot **board, struct Player *player);

#endif
