
#ifndef CLAN_H
#define CLAN_H
#include "Execptions.h"
#include <iostream>
#include "Tree.h"

class Clan{
    int ClanID;
    int ClanSize;
    Player* BestPlayer;
    Tree<Player*> ClanPlayersTree;





};


class Player{
    int PlayerID;
    Tree<Player*>::Node *ClanNode;
    Tree<Player*>::Node *CoinHolder;
    int Challenges;
    int Coins;
    Clan* clan;







};





#endif //WET1_CLAN_H
