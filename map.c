// body map.h

#include "map.h"
#include <stdio.h>


// ----------Constructor----------
void createMap(Map *M, int row, int col) {
	MapBrsEff(*M) = row;
	MapKolEff(*M) = col;
	for (int i = 0; i <= MapBrsEff(*M); i++) {
		for (int j = 0; j <= MapKolEff(*M); j++) {
			MapElmt(*M, i, j).bld = Nil;
			MapElmt(*M, i, j).chr = Nil;
		}
	}
}
// membuat map berukuran baris row dan kolom col


// ----------Output----------
void printMap(Map M) {
	int i, j;

	printf(" ");
	for (j = 0; j <= MapKolEff(M); j++) {
		printf("   %d", j);
	}
	printf("\n  ");

	for (i = 0; i <= MapBrsEff(M); i++) {
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("****");
		}
		printf("*\n  ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (MapElmt(M, i, j).bld == Nil) {
				printf("  ");
			}
			else {
				printf("%c ", MapElmt(M, i, j).bld);
			}
		}
		printf("*\n");
		printf("%d ", i);
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("* ");
			if (MapElmt(M, i, j).chr == Nil) {
				printf("  ");
			}
			else {
				printf("%c ", MapElmt(M, i, j).chr);
			}
		}
		printf("*\n  ");
		for (j = 0; j <= MapKolEff(M); j++) {
			printf("*   ");
		}
		printf("*\n  ");
	}
	for (j = 0; j <= MapKolEff(M); j++) {
		printf("****");
	}
	printf("*\n");
}
// Mengeprint map pada cmd