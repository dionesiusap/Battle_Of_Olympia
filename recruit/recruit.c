#include "recruit.h"

Build SearchTower(MAP M, Player P) {
    int owner_unit = ID(P);
    int i,j;

    for (i = 0; i <= MapBrsEff(M); i++){
        for (j = 0; j <= MapKolEff(M); j++){

            if ((Build_Type(Build(M, i, j)) == 'T') && (Build_Owner(Build(M, i, j)) == owner_unit)) {
            
                return Build(M, i, j);
            }
        }
    }

    return Build(M, 0, 0);
}

boolean IsCastleEmpty (MAP M, int x, int y){
    return (Type(Unit(M, x, y)) == Nil) ? true : false;
}

boolean castle_available(MAP M, Build T) {
    POINT tower = Build_Pos(T);
    POINT PC1, PC2, PC3, PC4;
    Build C1, C2, C3, C4;

    /* Get castle building info */
    C1 = Build(M, Absis(tower)+1, Ordinat(tower));
    C2 = Build(M, Absis(tower), Ordinat(tower)+1);
    C3 = Build(M, Absis(tower)-1, Ordinat(tower));
    C4 = Build(M, Absis(tower), Ordinat(tower)-1);

    /* Get castle position */
    PC1 = Build_Pos(C1);
    PC2 = Build_Pos(C2);
    PC3 = Build_Pos(C3);
    PC4 = Build_Pos(C4);

    /* Check if there's availabe castle */
    boolean castle_available = IsCastleEmpty(M, Absis(PC1), Ordinat(PC1)) || IsCastleEmpty(M, Absis(PC2), Ordinat(PC2)) || IsCastleEmpty(M, Absis(PC3), Ordinat(PC3)) || IsCastleEmpty(M, Absis(PC4), Ordinat(PC4)) ;

    return castle_available;
}

void recruit_unit(MAP *M, Player *P, UNIT K){
    int x, y;
    int choice;
    UNIT U;

    Build Tower = SearchTower(*M, *P);


    if (point_EQ(Pos(K), Build_Pos(Tower))){
        if (castle_available(*M, Tower)){
            do {
                printf("Enter coordinate of empty castle: ");
                scanf("%d %d", &x, &y);
                if (!IsCastleEmpty(*M, x, y)){
                    printf("That castle is occupied!\n");
                }
                if(Build_Owner(Build(*M,x,y))!=ID(*P)){
                    printf("That's not your castle!\n");
                }
            } while (!IsCastleEmpty(*M, x, y) || Build_Owner(Build(*M,x,y))!=ID(*P));

            printf("\n=== List of Recruits ===\n");
            printf("1. Archer | Health 100 | ATK 50 | DEF 30 | 10G\n");
            printf("2. Swordsman | Health 100 | ATK 60 | DEF 30 | 20G\n");
            printf("3. White Mage | Health 100 | ATK 5 | DEF 5 | HEAL 25 | 200G\n");
            printf("\n");
            printf("Enter no. of unit you want to recruit: ");
            scanf("%d", &choice);

            if (choice==1) {
                if (gold(*P)>=20) {

                    U = Create_new_unit('A', ID(*P), x, y);

                    upkeep(*P)=upkeep(*P)+Upkeep(U);
                    gold(*P)=gold(*P)-Cost(U);
                    Mov(U)=0;
                    Unit(*M, x, y) = U;
                    units(*P) = Insert_unit(units(*P), Pos(U), Index_Max(units(*P)));
                    printf("You have successfully recruited a(n) ");
                    print_unit_type(U);
                    printf("!\n");
                }
                else {
                    printf("You don't have any money.");
                }
            }

            else if (choice==2) {
                if (gold(*P)>=10) {

                    
                    U = Create_new_unit('S', ID(*P), x, y);

                    upkeep(*P)=upkeep(*P)+Upkeep(U);
                    gold(*P)=gold(*P)-Cost(U);
                    Mov(U)=0;
                    Unit(*M, x, y) = U;

                    units(*P) = Insert_unit(units(*P), Pos(U), Index_Max(units(*P)));
                    printf("You have successfully recruited a(n) ");
                    print_unit_type(U);
                    printf("!\n");
                }
                else {
                    printf("You don't have any money.");
                }
            }

            else if (choice==3) {
                if (gold(*P)>=200) {

                   
                    U = Create_new_unit('W', ID(*P), x, y);

                    upkeep(*P)=upkeep(*P)+Upkeep(U);
                    gold(*P)=gold(*P)-Cost(U);
                    Mov(U)=0;
                    Unit(*M, x, y) = U;
                    units(*P) = Insert_unit(units(*P), Pos(U), Index_Max(units(*P)));
                    printf("You have successfully recruited a(n) ");
                    print_unit_type(U);
                    printf("!\n");
                }
                else {
                    printf("You don't have any money.");
                }
            }

        }
        else{
            printf("You don't have any available tower.\n");
        }
    }
    else{
        printf("Your king must be inside your tower if you want to recruit any unit.");
    }

}
