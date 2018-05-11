
#ifndef CLAN_H
#define CLAN_H
#include "Execptions.h"
#include "Player.h"
#include <iostream>
#include "Tree.h"

class Clan{
    int ClanID;
    int ClanSize;
    Player* BestPlayer;
    Tree<Player*> ClanPlayersTree;





};







#endif //WET1_CLAN_H
