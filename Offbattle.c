
#include "matriks.h"
#include "point.h"
#include "Offbattle.h"
#include <stdlib.h>
#include <time.h>

/* LAST UPDATE : 11 NOV 2017 - 23 : 16 */

void Init_game(MATRIKS *MAP, int map_x, int map_y){
    /* Function to setup tower, castle, and villages before game starts */

    /* Constants */
    char tower_symbol = 'T';
    char castle_symbol = 'C';
    char village_symbol = 'V';
    int village_count = (int) map_x * map_y * 0.06;
    srand (time(NULL));


    void Set_element(MATRIKS *MAP, POINT index, char symbol){
        /* Procedure to set symbol into designated index in matrix */

        Elmt(*MAP, Absis(index), Ordinat(index)) = symbol;
    }

    int Village_too_close(POINT index, int map_x, int map_y){
        /* Function to check wether a village position is too close to tower or not */

        int min_distance_from_edge = 2 + (int)((map_x + map_y) *2 / 15);

        if ((Absis(index) < min_distance_from_edge) && (Ordinat(index) > map_y - min_distance_from_edge)){

            /* Too close to bottom-left tower */
            return 1;
        }

        else if ((Absis(index) > map_x - min_distance_from_edge) && (Ordinat(index) < min_distance_from_edge)){

            /* Too close to upper-right tower */
            return 1;
        }

        else{

            return 0;
        }
    }


    /* Determine the tower and castle position */
    POINT tower_1 = MakePOINT(map_x -1,        1);
    POINT tower_2 = MakePOINT(1       , map_y -1);

    POINT castle_1a = MakePOINT(Absis(tower_1) -1, Ordinat(tower_1)   );
    POINT castle_1b = MakePOINT(Absis(tower_1)   , Ordinat(tower_1) -1);
    POINT castle_1c = MakePOINT(Absis(tower_1) +1, Ordinat(tower_1)   );
    POINT castle_1d = MakePOINT(Absis(tower_1)   , Ordinat(tower_1) +1);

    POINT castle_2a = MakePOINT(Absis(tower_2) -1, Ordinat(tower_2)   );
    POINT castle_2b = MakePOINT(Absis(tower_2)   , Ordinat(tower_2) -1);
    POINT castle_2c = MakePOINT(Absis(tower_2) +1, Ordinat(tower_2)   );
    POINT castle_2d = MakePOINT(Absis(tower_2)   , Ordinat(tower_2) +1);


    /* Place tower and castle in position */
    // [MIGHT NEED SOME ADJUSTMENT, MAP element will be a struct]
    Set_element(MAP, tower_1, tower_symbol);
    Set_element(MAP, tower_2, tower_symbol);

    Set_element(MAP, castle_1a, castle_symbol);
    Set_element(MAP, castle_1b, castle_symbol);
    Set_element(MAP, castle_1c, castle_symbol);
    Set_element(MAP, castle_1d, castle_symbol);

    Set_element(MAP, castle_2a, castle_symbol);
    Set_element(MAP, castle_2b, castle_symbol);
    Set_element(MAP, castle_2c, castle_symbol);
    Set_element(MAP, castle_2d, castle_symbol);


    /* Setup villages */
    int village_area_x = map_x - 5;
    int village_area_y = map_y - 5;

    while(village_count != 0){

        /* Create village location */
        POINT village = MakePOINT(rand() % map_x, rand() % map_y);

        /* Check enability of map to put village in that position */
        char content = Elmt(*MAP, Absis(village), Ordinat(village));
        int too_close = Village_too_close(village, map_x, map_y);

        if (content != castle_symbol && content != tower_symbol && !too_close){

            /* If possible */
            Set_element(MAP, village, village_symbol);
            village_count--;

        }
    }
}
