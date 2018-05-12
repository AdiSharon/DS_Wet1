
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


struct Coins {
    int numCoins;
    int playerID;
    int clanID;
} *Coins;


class Clan{

    int ClanId;
    int ClanSize;
    Player* BestPlayer;
    Tree<Player*> ClanPlayersTree;

public:

    Clan(int clanID);

    ~Clan();

    ClanStatusType AddPlayerToClan(Player* player );

    Player* getBestPlayer();

    int getClanSize();

    int getID();

    //Player* FindPlayerInClanByID(int id);


};


class Player{
    int PlayerID;
    Tree<Player*>::Node *ClanNode;
    Tree<Player*>::Node *CoinHolder;
    int Challenges;
    int Coins;
    Clan* clan;
public:


    Player(int ID, int coins);

    ~Player();

    //after Oasis has found the clan & player, updates the clan pointer
    ClanStatusType updateClan(Tree<Player*>::Node *ClanNode);

    ClanStatusType completeChallange(int coins);

    //
    ClanStatusType updateCoins(int coins);

    /*
     * if this is greater than other, return >0
     */
    //int compareById(Player other);

    //int compareByCoin(Player other);

    int getID();

    int getChallenges();

    Clan* getClan();


};

class PlayerCompByID{
public:
    int operator()(Player a, Player b){
        return a.getID()-b.getID();
    }
};

class ClanCompByID{
public:
    int operator()(Clan a, Clan b){
        return a.getID()-b.getID();
    }
};

class CoinsCompFunc{
public:
    int operator()(Coins a, Coins b){
        if(a.numCoins > b.numCoins){
            return -1;
        } else if (a.numCoins < b.numCoins){
            return 1;
        } else{
            return a.playerID - b.playerID;
        }
    }
};



#endif //WET1_CLAN_H
