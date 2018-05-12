
#include "Oasis.h"
#include "Execptions.h"
#include <iostream>


// c'tor /////////// FIX IIIIIIIIITTTTTTTTTTT
Oasis::Oasis() :
MostCoins(NULL),
BestPlayer(NULL) {
    PlayerTree = Tree<Player>();
    ClanTree = Tree<Clan>();
    CoinTree = Tree<Coins>();

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
         delete (newPlayer);
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

    Clan *newClan = new Clan(ClanId);

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
        delete(dummy);
        return OasisFAILURE; //the player is not in the system.
    }
    if (player_to_add->getNodeData()->getClan() != NULL){
        delete(dummy);
        return OasisFAILURE; //player is already in a clan.
    }
    Clan *dummy_clan = new Clan(ClanID);
    Tree<Clan>::Node* clan_to_add_to;
    try {
        clan_to_add_to = this->ClanTree.find(*dummy_clan, this->ClanTree.getRoot(), ClanCompByID::operator());
    } catch (TreeNodeDoesNotExit){
        delete(dummy);
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
            return OasisSUCCESS;

    }
}

OasisStatusType Oasis:: completeChallange(int playerID, int coins){
    if(playerID<0 ||coins<0)
        return OasisINVALID_INPUT;
    Player *dummy = new Player(playerID, 0);
    Tree<Player>::Node* player_to_find;
    try{
        player_to_find = this->PlayerTree.find(*dummy, this->PlayerTree.getRoot(), PlayerCompByID::operator());
    } catch (TreeNodeDoesNotExit){
        delete(dummy);
        return OasisFAILURE; //the player is not in the system.
    }
    player_to_find->getNodeData()->completeChallange(coins);
    delete(dummy);
    //we are checking if after updating the number of challenges,we have a new Oasid best player
    if(this->BestPlayer->getChallenges() < player_to_find->getNodeData()->getChallenges())
        this->BestPlayer=player_to_find->getNodeData();

    // if our changed player is now equal in num of challenges to the best, we take the smaller identifier
    else if(this->BestPlayer->getChallenges() == player_to_find->getNodeData()->getChallenges()) {
        if (player_to_find->getNodeData()->getID() >= this->BestPlayer->getID())
            this->BestPlayer = player_to_find->getNodeData();
    }

     // DOING THE SAME DAMN THING, BUY THIS TIME ON THE CLAN'S BEST PLAYER

    if(player_to_find->getNodeData()->getClan()->getBestPlayer()->getChallenges() <
            player_to_find->getNodeData()->getChallenges())
        this->BestPlayer=player_to_find->getNodeData();

        // if our changed player is now equal in num of challenges to the best, we take the smaller identifier
    else if(player_to_find->getNodeData()->getClan()->getBestPlayer()->getChallenges()
            == player_to_find->getNodeData()->getChallenges()) {
        if (player_to_find->getNodeData()->getClan()->getBestPlayer()->getID() >= this->BestPlayer->getID())
            this->BestPlayer = player_to_find->getNodeData();
    }




    return OasisSUCCESS;
}


OasisStatusType Oasis::getBestPlayer(int clanID, int *playerID){
    if(playerID==NULL || clanID==0)
        return OasisINVALID_INPUT;
    if(clanID>=0) {
        Clan *dummy = new Clan(clanID);
        Tree<Clan>::Node *clan_to_find;
        try {
            clan_to_find = this->ClanTree.find(*dummy, this->ClanTree.getRoot(), ClanCompByID::operator());
        } catch (TreeNodeDoesNotExit) {
            delete (dummy);
            return OasisFAILURE; //the player is not in the system.
        }
        Player *Bestplayer = clan_to_find->getNodeData()->getBestPlayer();
        if (Bestplayer == NULL)
            return


    }
    else


}

OasisStatusType Oasis:: getScoreboard(int clanID, int **players, int *numOfPlayers);

OasisStatusType Oasis:: uniteClans(int clanID1, int clanID2);

void Oasis::Quit();


OasisStatusType Oasis::updateCoinsTree(int playerID, int oldCoins, int addedCoins, Player* player){
    Coins *dummy = new Coins(oldCoins, playerID, player);
    Tree<Coins>::Node *temp;
    try{
        this->CoinTree.remove(*dummy, CoinsCompFunc::operator());
    } catch (TreeNodeDoesNotExit){
        return OasisFAILURE;
    }
    Coins *coins = new Coins(oldCoins+addedCoins, playerID, player);
    try {
        this->CoinTree.insert(*coins, this->CoinTree.getRoot(), CoinsCompFunc::operator());
    } catch (TreeMemoryProblemException){
        return OasisALLOCATION_ERROR;
    }
    return OasisSUCCESS;
}