
/* Module to handle unit list */

#ifndef unitlist_H
#define unitlist_H

#include "../unit/unit.h"
#include "../unit_battle/unit_battle.h"
#include "../map/map.h"
#include "../ADT/point.h"

#include <stdlib.h>

typedef POINT infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    int index;
	infotype info;
	address next;
} ElmtList;

typedef address UnitList;

#define Index(P) (P)->index
#define Info(P) (P)->info
#define Next(P) (P)->next


/****************** ADD AND DEL ******************/
UnitList Insert_unit(UnitList L, POINT unit_pos, int indeks);
/* Insert a element into list */

void Delete_unit (UnitList *L, int Index);
/* Delete an element at index X */

void select_unit(MAP *Map, UnitList Unit_list, UNIT * Current_unit, int Index);
/* Change value of current unit by selecting unit in unitlist by index */

UnitList change_unit_position_pre(UnitList Unit_list, UNIT *Current_unit, int *unit_index_in_list);
/* Function to delete unit in unitlist and store index */

UnitList change_unit_position_post(UnitList Unit_list, UNIT *Current_unit, int unit_index_in_list);
/* Function to insert unit in unitlist after the position is modified */

void selected_on_map_ON(MAP *Map, UNIT *Current_unit, boolean Cond);
/* Function to turn on and off 'select' atribut in map */

int search_next_unit(MAP *M, UnitList Unit_list,UNIT *Current_unit);
/* function to return next index of unit that can move / attack */

/****************** DISPLAY ******************/
void Display_unit_list (MAP M, UnitList L);
/* Display unit index and unit position */

void show_unit_in_list(UNIT U, int Index);
/* Function to show unit data  */

void refresh_unit_list(MAP *M,UnitList L);
/* Refresh Can_Atk,Mov all Unit in UnitList */

void do_heal(MAP *M,UnitList L);
/* Heal with your white mage */

/****************** SHOULD NOT BE USED DIRECTLY ******************/
int UnitList_empty(address L);

address Alokasi_point(infotype X, int indeks);

int UnitNbElmt(UnitList L);

int Index_Max(UnitList L);

UnitList Tail(UnitList L);

POINT get_unit_position(UnitList L, int Index);
/* Function to return unit position stored in unitlist by indexing */

int search_current_unit_index(UnitList Unit_list, UNIT *Current_unit);
/* Function to return index of current unit in unitlist */

void refreshMap(MAP *M, UnitList L);

#endif
