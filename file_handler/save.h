#include <stdio.h>
#include <math.h>
#include "../ADT/mesinkata.h"
#include "../ADT/boolean.h"
#include "../player_handler/player.h"

int KataToInt (Kata K);

boolean IsKataSama (Kata K1,Kata K2);

void SaveGame(Player P1, Player P2);

void LoadGame(Player *P1, Player *P2);