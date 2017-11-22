#include "player.h"
#include "unitlist.h"
#include "villagelist.h"

void InitializeNewPlayer(Player *P, int ID){
	ID(*P) = ID;
	gold(*P) = 40;
	income(*P) = 0;
	upkeep(*P) = 0;
	creteEmpty_unit(units(*P));
	if (ID==1){
		color(*P) = 'R';
	}
	else if (ID==2){
		color(*P) = 'G';
	}
	else if (ID==1){
		color(*P) = 'Y';
	}
	else if (ID==1){
		color(*P) = 'B';
	}
	else if (ID==1){
		color(*P) = 'M';
	}
	else if (ID==1){
		color(*P) = 'C';
	}
}

Player create_new_player(int ID){
	Player new_player;

	InitializeNewPlayer(&new_player, ID);
	return new_player;
}