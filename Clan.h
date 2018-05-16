
#ifndef CLAN_H
#define CLAN_H
#include "Execptions.h"
#include <iostream>
#include "Tree.h"


class Player;
class Clan;
class Coins;


typedef enum {
    ClanSUCCESS = 0,
    ClanFAILURE = -1,
    ClanALLOCATION_ERROR = -2,
    ClanINVALID_INPUT = -3
} ClanStatusType;


class Coins {
    int numCoins;
    int playerID;
    Player *player;


public:

    Coins (int numCoins, int playerID, Player* player);

    ~Coins();

    Coins(const Coins &coins);

    bool operator==(const Coins& coins) const;

    Coins& operator=(const Coins& coins);

    int getNumCoins();

    int getPlayerId();

    int getCoinsClan();

    void updateCoins(int addedCoins);

    int getClanID();

    Clan* getCoinsClansClan();

} ;

//-------------------------------------------------------------------
class Clan{

    int ClanId;
    // int ClanSize;
    Player* BestPlayer;
    Tree<Player*> ClanPlayersTree;

public:

    Clan(int clanID);

    Clan(const Clan &clan);

    ~Clan();

    bool operator==(const Clan& clan) const;

    Clan& operator=(const Clan& clan);

    ClanStatusType AddPlayerToClan(Player* player );

    Player* getBestPlayer();

    void updateBestPlayer(Player* player);

    int getClanSize();

    void upateBestPlayer(Player* player);

    int getID();

    ClanStatusType ClanSwalalala(Clan* smallClan);
    //Player* FindPlayerInClanByID(int id);

    //static int ClanPlayerCompByID(Player *a, Player *b);


};

//-------------------------------------------------------------------
class Player{
    int PlayerID;
    Tree<Player*>::Node *ClanNode;
    Tree<Coins>::Node *CoinHolder;
    int Challenges;
    int coins;
    Clan* clan;
public:

    Player(const Player &player);

    Player& operator=(const Player& player);

    bool operator==(const Player& player) const;

    Player(int ID, int coins);

    ~Player();

    //after Oasis has found the clan & player, updates the clan pointer
    ClanStatusType updateClanNode(Tree<Player*>::Node *ClanNode);

    void updateClan(Clan *clan);

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

    int getNumCoins();

    Clan* getClan();

    void removeFromClan();

};

/*class PlayerCompByID{
public:
    int operator()(Player a, Player b){
        return a.getID()-b.getID();
    }
};*/

/*class ClanPlayerCompByID{
public:
    int operator()(Player *a, Player *b){
        return a->getID()-b->getID();
    }
};*/

/*class ClanCompByID{
public:
    int operator()(Clan a, Clan b){
        return a.getID()-b.getID();
    }
};*/

/*class CoinsCompFunc{
public:
    int operator()(Coins a, Coins b){
        if(a.getNumCoins() > b.getNumCoins()){
            return -1;
        } else if (a.getNumCoins() < b.getNumCoins()){
            return 1;
        } else{
            return a.getPlayerId() - b.getPlayerId();
        }
    }
};*/

/*class findRemoveFromClan{
public:
    bool operator()(Player *player){
        if(player->getChallenges()==0){
            player->removeFromClan();
            return true;
        }
        else
            return false;
    }
};*/




#endif //WET1_CLAN_H
