#include "map.h"
#include <stdio.h>
#include "Offbattle.h"
#include "unit.h"
#include "unit_battle.h"
#include "move.h"
#include "turn.h"
#include "player_handler/player.h"
#include "player_handler/unitlist.h"


int main() {

	Show_title();

	/* Initialization */
	Player player_1 = create_new_player(1);
	Player player_2 = create_new_player(2);
	Player* Current_player; int Current_player_int;

	MAP M = Init_map();
	Queue TURN = Init_turn();

	Init_game(&M, &player_1, &player_2);

	UNIT Dummy_unit = Create_new_unit('Z', 0, 0, 0); // dummy unit
	UNIT* Current_unit = &Dummy_unit;
	
	char input = 'E'; //automatic start first turn

	
	// DUMMY TEST material (for attack and move )

	POINT point;
	Unit(M, 1, 1) = Create_new_unit('S',1,1,1);
	point = MakePOINT(1,1);
	units(player_1) = Insert_unit(units(player_1), point, UnitNbElmt(units(player_1)));
	
	Unit(M, 1, 2) = Create_new_unit('S',2,1,2);
	point = MakePOINT(1,2);
	units(player_2) = Insert_unit(units(player_2), point, UnitNbElmt(units(player_2)));

	while(input != 'Q'){

		if (input == 'W'){
			/* Print map */
			printMap(M);
		}

		else if(input == 'A'){
			/* Command to declare attack using current unit */
			attack(Current_unit, &M);
		}

		else if(input == 'M'){
			/* Command to move unit */

			int x,y;

			print_possible_move(M, *Current_unit);
			printf("Moving into : ");
			scanf("%d %d", &x, &y);
			if(check_if_possible(M, *Current_unit, x, y)){
				move_unit(&M, Current_unit, x, y);
				printf("Unit moved\n");
			}
			else{
				printf("\nThat unit can't be placed there...\n");
			}
		}

		else if(input == 'C'){
			/* Switching current unit */

			int unit_list_index;

			Display_unit_list(M, units(*Current_player));
			printf("Switching into unit : ");
			scanf("%d", &unit_list_index);
			select_unit(M, units(*Current_player), Current_unit, unit_list_index);
    		
		}

		else if(input == 'S'){
			/* Show current unit info */
			
			printf(" ========================\n");
		    printf("|    Player %d's Unit     |\n",Owner(*Current_unit));
		    printf(" ========================\n");
			Show_unit_info(*Current_unit);
			printf("\n");
		}

		else if(input == 'E'){
			/* End turn */

			Switch_turn(&TURN, &Current_player_int);
			if (Current_player_int == 1){
				Current_player = &player_1;
			}
			else if(Current_player_int == 2){
				Current_player = &player_2;
			}

			// increase gold , decrease gold , healing 
		}


		/* Get new input */
		scanf("%c",&input); // remove enter at last 
		printf("\ninput your next command ! >> ");
		scanf("%c",&input);
		printf("\n");
	}
}
