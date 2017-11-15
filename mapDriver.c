#include "map.h"
#include "building.h"
#include <stdio.h>

int main() {
	MAP M;
	int col, row;

	printf("Insert size of map (max is 9x10)\n(e.g. 5 9 means 5x9) : ");
	scanf("%d %d", &col, &row);
	while (col < 8 || col > 9 || row > 10 || row < 8) {
		printf("Sorry, I think it's too big.\n");
		printf("or maybe too small?\n");
		printf("Please insert it again : ");
		scanf("%d %d", &col, &row);
	}

	createMap(&M, col, row);
	Unit(M, 1, 5).type = 'K';
	Unit(M, 1, 5).owner = 1;


	Unit(M, 2, 4).type = 'K';
	Unit(M, 2, 4).owner = 2;
	
	Unit(M, 3, 5).type = 'K';
	Unit(M, 3, 5).owner = 0;
	
	MapElmt(M, 2, 3).bld = 'V';
	printMap(M);
	return 0;
}