#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
int Num=0;// a global variable for the amount of the slots.
struct slot // maybe not necessary for just one item below.
{
	int row[10];
	int column[10];
	char type[7][7];
};
struct character //
{
	int slot[10];// an array for each player's slot currently from player 1 to player 6.
	char slotType[10][10];
	char type[10][10];// a two direction array for each player's type (eg: elf) from player 1 to player 6.
	char name[10][20];// a two direction array for each player's name from player 1 to player 6.
	int lifepoint[10];  // an array for each player's lifepoint from player 1 to player 6.
	int smartness[10];// an array for each player's smartness from player 1 to player 6.
	int strength[10];// an array for each player's strength from player 1 to player 6.
	int magic[10];// an array for each player's magic from player 1 to player 6.
	int luck[10];// an array for each player's luck from player 1 to player 6.
	int dexterity[10];// an array for each player's dexterirty from player 1 to player 6.
	int alive[10];//an array if the player quit the game.
};
struct slot myslot;
struct character mycharacter;
void type(int player);  // a function to get each player's type and go to each type's function.
void slot(int player);// a function to get the amount of slot and randomise the type of slots.
void elf(int player) ;// if the player is an elf, randomly generate the capabilities as demanded in part B.
void human(int player);// if the player is an human, randomly generate the capabilities as demanded in part B.
void orge(int player);// if the player is an orge, randomly generate the capabilities as demanded in part B.
void wizard(int player);// if the player is an wizard, randomly generate the capabilities as demanded in part B.
void assign(int player);// give each player an initial position(slot), without any player get the same slot.
void action(int player);  // ask each the action he wants to do, (eg: move to the next slot or attack)
void move(int playerNum, int playerAll); // if the player choose to move, change the capability of the player as the C part described.
void attack();  // if the player choose to attack, change the capability of the player as the part D described.
int main(void)
{
	srand(time(NULL)); // to use rand().
	int player;
	printf("Enter the number of players.(2-6)\n");
	do
	{
	    scanf("%d",&player);
		int playerNum =player;
		if (playerNum>1 && playerNum < 7)
		{
            type(player);
			slot(player);
			assign(player);
			action(player);
		}

		else
		{
			printf("please enter a number between 2 and 6.\n");//if the user enter a number greater than 6 or smaller than 1.
		}
	}while (player>6||player<2);
	int p;
	for(p=1;p<=player;p++)   // print the state as the part A require at the last part.
	{
		printf("%s(%s,%d)\n",mycharacter.name[p],mycharacter.type[p],mycharacter.lifepoint[p]);
	}


}
void type(int player)
{
	int i=1;
	int j;
	do
	{
        printf("The %d player please select the type you want(1 for elf, 2 for human, 3 for orge, 4 for wizard.\n",i);
		while (j>4 || j<1)
		{


		    do
		    {
			    scanf("%d",&j);
			    if (j==1)
				{
					elf(i);
				}
			    else if(j==2)
				{
					human(i);
				}
			    else if(j==3)
				{
					orge(i);
				}
			    else if(j==4)
				{
					wizard(i);
				}
				else
				{
					printf("please enter a number between 1 and 4\n");
				}
		    }while(j!=1&&j!=2&&j!=3&&j!=4);
		}
		player--;
		i++;
		j=0;
	}while(player != 0);
	char *ab;
	printf("Now that everyone has finished choosing the type and name.\nEnter anything to go to the next step.\n");
	scanf("%s",&ab);
}
void slot(int player)
{
	int Num;
    for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			Num=rand()%3;
			if(Num==0)
			{
				char type[20]="Level Ground";
				strcpy(myslot.type[i][j],type);
			}
			else if(Num==1)
			{
				char type[6]="Hill";
				strcpy(myslot.type[i][j],type);
			}
			else if(Num==2)
			{
			    char type[6]="City";
				strcpy(myslot.type[i][j],type);
			}
				printf("%s    ",myslot.type[i][j]);
		}
	printf("\n");
	}

}
void elf(int player)
{
	printf("Please enter the name for your character.\n");
	scanf("%s",mycharacter.name[player]);
	char t[10] = "elf";
	strcpy(mycharacter.type[player],t);
	mycharacter.lifepoint[player]=100;
	mycharacter.luck[player]=rand()%40+60;
	mycharacter.smartness[player]=rand()%30+70;
	mycharacter.strength[player]=rand()%50+1;
	mycharacter.magic[player]=rand()%29+51;
	mycharacter.dexterity[player]=rand()%100+1;
	mycharacter.alive[player]=1;
	printf("%d player,",player);
	printf("you are %s, your name is %s\n",mycharacter.type[player],mycharacter.name[player]);
	printf("Your abilities are %d luck,%d strength, %d smartness, %d magic,%d dexterity and you have 100 lifepoint.\n",mycharacter.luck[player],mycharacter.strength[player],mycharacter.smartness[player],mycharacter.magic[player],mycharacter.dexterity[player]);
}
void human(int player)
{
	printf("Please enter the name for your character.\n");
	scanf("%s",mycharacter.name[player]);
	char t[10] = "human";
	strcpy(mycharacter.type[player],t);
	mycharacter.lifepoint[player]=100;
	mycharacter.alive[player]=1;
    do
	{
		mycharacter.smartness[player]=rand()%100+1;
		mycharacter.strength[player]=rand()%100+1;
		mycharacter.magic[player]=rand()%100+1;
		mycharacter.dexterity[player]=rand()%100+1;
		mycharacter.luck[player]=rand()%100+1;
	} while(mycharacter.smartness[player]+mycharacter.strength[player]+mycharacter.dexterity[player]+mycharacter.magic[player]+mycharacter.luck[player]>299);
	printf("%d player,",player);
	printf("you are %s, your name is %s\n",mycharacter.type[player],mycharacter.name[player]);
	printf("Your abilities are %d luck,%d strength, %d smartness, %d magic,%d dexterity and you have 100 lifepoint.\n",mycharacter.luck[player],mycharacter.strength[player],mycharacter.smartness[player],mycharacter.magic[player],mycharacter.dexterity[player]);
}
void orge(int player)
{
	printf("Please enter the name for your character.\n");
	scanf("%s",mycharacter.name[player]);
	char t[10] = "orge";
	strcpy(mycharacter.type[player],t);
	mycharacter.lifepoint[player]=100;
	mycharacter.smartness[player]=rand()%21;
	mycharacter.strength[player]=rand()%21+80;
	mycharacter.dexterity[player]=rand()%21+80;
	mycharacter.magic[player]=0;
	mycharacter.luck[player]=rand()%(50-mycharacter.smartness[player])+1;
	mycharacter.alive[player]=1;
	printf("%d player,",player);
	printf("you are %s, your name is %s\n",mycharacter.type[player],mycharacter.name[player]);
	printf("Your abilities are %d luck,%d strength, %d smartness, %d magic,%d dexterity and you have 100 lifepoint.\n",mycharacter.luck[player],mycharacter.strength[player],mycharacter.smartness[player],mycharacter.magic[player],mycharacter.dexterity[player]);
}

void wizard(int player)
{
	printf("Please enter the name for your character.\n");
	scanf("%s",mycharacter.name[player]);
		char t[10] = "wizard";
	strcpy(mycharacter.type[player],t);
	mycharacter.lifepoint[player]=100;
	mycharacter.smartness[player]=rand()%11+90;
	mycharacter.strength[player]=rand()%20+1;
	mycharacter.dexterity[player]=rand()%100+1;
	mycharacter.magic[player]=rand()%21+80;
	mycharacter.luck[player]=rand()%51+50;
	mycharacter.alive[player]=1;
	printf("%d player,",player);
	printf("you are %s, your name is %s\n",mycharacter.type[player],mycharacter.name[player]);
	printf("Your abilities are %d luck,%d strength, %d smartness, %d magic,%d dexterity and you have 100 lifepoint.\n",mycharacter.luck[player],mycharacter.strength[player],mycharacter.smartness[player],mycharacter.magic[player],mycharacter.dexterity[player]);
}
void assign(int player)
{
   do{
	   myslot.row[player]=rand()%7;
	   myslot.column[player]=rand()%7;
	   player--;
   }while(player!=0);
}
void action(int player)
{
	char *sd;
	printf("Now it is time for action.Enter anthing to go on.\n");
	scanf("%s",&sd);
	int i=1;
	int game=1;
	int choice;
    int playerNum;
	int check=0;
	int count=0;
	playerNum=player;
	do
	{

	    printf("%d player,what do you want to do?(1 for move, 2 for attack the nearest player,3 for quit the game.)\n",i);
		do
		{
		    scanf("%d",&choice);
			if (choice==1)
			{
				move();
			}
			else if (choice==2)
			{
				attack();
			}
			else if (choice==3)
			{
			   mycharacter.alive[playerNum]=0;
			}
			else
			{
				printf("Please enter a number 1 or 2.(1 for move, 2 for attack the nearest player,3 for quit the game.))\n")	;
			}
		}while(choice!=1&&choice!=2&&choice!=3);
		for (int q=0;q<player;q++)
		{
			if(mycharacter.lifepoint[q]!=0)
			{
				count++;
			}

		}
		if (count==1)
			{
				game=0;
			}
		for (int j=0;j<player;j++)
		{
             if (mycharacter.alive[j]==1);
			 {
				 check=1;
			 }
		}
		if(check==1)
		{
			game=1;
		}
		if(check==0)
		{
			game=0;
		}
		if(game==1)
		{
            i=i+1;
			playerNum=playerNum-1;
			if (playerNum = 0)
			{
				playerNum=player;
			}
			while(mycharacter.alive[playerNum]!=0)
			{
				i=i+1;
				playerNum=playerNum-1;
			}
		}
	}while(game!=1);
}
void move(int playerNum,int playerAll)
{

}
void attack()
{

}
