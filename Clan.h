
#ifndef CLAN_H
#define CLAN_H
#include "Execptions.h"
#include <iostream>
#include "Tree.h"



typedef enum {
    ClanSUCCESS = 0,
    ClanFAILURE = -1,
    ClanALLOCATION_ERROR = -2,
    ClanINVALID_INPUT = -3
} ClanStatusType;



class Clan{

    int ClanId;
    int ClanSize;
    Player* BestPlayer;
    Tree<Player*> ClanPlayersTree;

public:
    Clan();

    ~Clan();

    ClanStatusType AddPlayerToClan(int PlayerId);

    Player* getBestPlayer();

    int getClanSize();

    Player* FindPlayerInClanByID(int ID);


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

    Player(int ID, int coins);

    ~Player();

    //after Oasis has found the clan & player, updates the clan pointer
    ClanStatusType updateClan(Tree<Player*>::Node *ClanNode);

    ClanStatusType completeChallange(int coins);

    //
    ClanStatusType updateCoins(Tree<Player*>::Node *CoinHolder);

    /*
     * if this is greater than other, return >0
     */
    //int compareById(Player other);

    int compareByCoin(Player other);

    int getID();



};

class PlayerCompByID{
public:
    int operator()(Player a, Player b){
        return a.getID()-b.getID();
    }
};



#endif //WET1_CLAN_H
