
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
public:

    Player();

    ~Player();

    //after Oasis has found the clan & player, updates the clan pointer
    void updateClan(Tree<Player*>::Node *ClanNode);

    void completeChallange(int coins);

    //
    void updateCoins(Tree<Player*>::Node *CoinHolder);

    /*
     * if this is greater than other, return >0
     */
    int compareById(Player other);

    int compareByCoin(Player other);

};





#endif //WET1_CLAN_H
