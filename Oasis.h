

#ifndef WET1_OASIS_H
#define WET1_OASIS_H
#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"



using std::iostream;

class Oasis{
    Tree<Player> PlayerTree;


    Tree<Clan> ClanTree;
    Tree<Player*> CoinTree;
    Player *MostCoins;
    Player *BestPlayer;

};




#endif //WET1_OASIS_H
