
#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#ifndef PLAYER_H
#define PLAYER_H
#include "Clan.h"


using std::iostream;


class Player{
    int PlayerID;
    Tree<Player*>::Node *ClanNode;
    Tree<Player*>::Node *CoinHolder;
    int Challenges;
    int Coins;
    Clan* clan;









};







#endif //WET1_PLAYER_H
