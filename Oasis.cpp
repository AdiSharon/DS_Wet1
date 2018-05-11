
#include "Oasis.h"
#include "Execptions.h"
#include <iostream>


// c'tor /////////// FIX IIIIIIIIITTTTTTTTTTT
Oasis::Oasis() :
MostCoins(NULL),
BestPlayer(NULL) {
    PlayerTree = Tree<Player>();
    ClanTree = Tree<Clan>();
    CoinTree = Tree<Player *>();

}

// d'tor  //DO ITTTTTTTTTTTTTTTTTTTT
Oasis::~Oasis() {

}

OasisStatusType Oasis:: addPlayer (int playerID, int initialCoins){
     Player *newPlayer= new Player(playerID, initialCoins);
     this->PlayerTree.insert(newPlayer,this->PlayerTree.getRoot(PlayerTree),CMP());

}

int CMP( Clan Clan1 ,Clan Clan2){

    return  Clan1.getClanSize()-Clan1.getClanSize();
}


OasisStatusType addClan(int ClanId);

OasisStatusType joinClan(int playerID, int ClanID);

OasisStatusType completeChallange(int playerID, int coins);

OasisStatusType getBestPlayer(int clanID, int *playerID);

OasisStatusType getScoreboard(int clanID, int **players, int *numOfPlayers);

OasisStatusType uniteClans(int clanID1, int clanID2);

void Quit();
