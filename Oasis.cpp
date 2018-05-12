
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
     Player *newPlayer = new Player(playerID, initialCoins);

     try{
         this->PlayerTree.insert(*newPlayer,this->PlayerTree.getRoot(),PlayerCompByID::operator());
     } catch (TreeMemoryProblemException){
         return OasisALLOCATION_ERROR;
     } catch (TreeDataAlreadyExists){
         return OasisFAILURE;
     }
    return OasisSUCCESS;

}

int CMP( Clan Clan1 ,Clan Clan2){

    return  Clan1.getClanSize()-Clan1.getClanSize();
}


OasisStatusType Oasis:: addClan(int ClanId){

    if(this==NULL||ClanId<0)
        return OasisINVALID_INPUT;

    Clan *newClan = new Clan(int ClanId);

    try{
        this->ClanTree.insert(*newClan, this->ClanTree.getRoot(), ClanCompByID::operator());
    } catch (TreeMemoryProblemException) {
        return OasisALLOCATION_ERROR;
    } catch (TreeDataAlreadyExists){
        return OasisFAILURE;
    }
    return OasisSUCCESS;
}

OasisStatusType Oasis:: joinClan(int playerID, int ClanID){
    if (playerID <= 0 || ClanID <= 0){
        return OasisINVALID_INPUT;
    }
    Player *dummy = new Player(playerID, 0);
    Tree<Player>::Node* player_to_add;
    try{
        player_to_add = this->PlayerTree.find(*dummy, this->PlayerTree.getRoot(), PlayerCompByID::operator());
    } catch (TreeNodeDoesNotExit){
        return OasisFAILURE; //the player is not in the system.
    }
    if (player_to_add->getNodeData()->getClan() != NULL){
        return OasisFAILURE; //player is already in a clan.
    }
    Clan *dummy_clan = new Clan(ClanID);
    Tree<Clan>::Node* clan_to_add_to;
    try {
        clan_to_add_to = this->ClanTree.find(*dummy_clan, this->ClanTree.getRoot(), ClanCompByID::operator());
    } catch (TreeNodeDoesNotExit){
        return OasisFAILURE; //clan ID isn't in Oasis
    }
    delete(dummy);
    Player *ptr = player_to_add->getNodeData();
    switch (clan_to_add_to->getNodeData()->AddPlayerToClan(ptr)){
        case (ClanALLOCATION_ERROR):
            return OasisALLOCATION_ERROR;
        case (ClanINVALID_INPUT):
            return OasisINVALID_INPUT;
        case (ClanFAILURE):
            return OasisFAILURE;
        case (ClanSUCCESS):
            return OasisSUCCESS

    }
}

OasisStatusType Oasis:: completeChallange(int playerID, int coins);

OasisStatusType Oasis:: getBestPlayer(int clanID, int *playerID);

OasisStatusType Oasis:: getScoreboard(int clanID, int **players, int *numOfPlayers);

OasisStatusType Oasis:: uniteClans(int clanID1, int clanID2);

void Oasis::Quit();
