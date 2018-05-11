
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
    if(playerID<0 || initialCoins<0 || this==NULL)
        return OasisINVALID_INPUT;
     Player *newPlayer= new Player(playerID, initialCoins);
     this->PlayerTree.insert(*newPlayer,this->PlayerTree.getRoot(PlayerTree),CMP(Clan1,Clan2));

}

/*int Oasis:: CMP( Clan Clan1 ,Clan Clan2){

    return  Clan1.getClanSize()-Clan1.getClanSize();
}*/


OasisStatusType Oasis:: addClan(int ClanId){

    if(this==NULL||ClanId<0)
        return OasisINVALID_INPUT;



}

OasisStatusType Oasis:: joinClan(int playerID, int ClanID);

OasisStatusType Oasis:: completeChallange(int playerID, int coins);

OasisStatusType Oasis:: getBestPlayer(int clanID, int *playerID);

OasisStatusType Oasis:: getScoreboard(int clanID, int **players, int *numOfPlayers);

OasisStatusType Oasis:: uniteClans(int clanID1, int clanID2);

void Oasis::Quit();
