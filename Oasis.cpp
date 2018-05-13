
#include "Oasis.h"
#include "Execptions.h"
#include <iostream>


// c'tor /////////// FIX IIIIIIIIITTTTTTTTTTT
Oasis::Oasis() :
MostCoins(NULL),
BestPlayer(NULL) {
    PlayerTree = *(new Tree<Player>());
    ClanTree = *(new Tree<Clan>());
    CoinTree = *(new Tree<Coins>());

}

// d'tor  //DO ITTTTTTTTTTTTTTTTTTTT
Oasis::~Oasis() {
    PlayerTree.deleteTree();
    delete (&PlayerTree);
    ClanTree.deleteTree();
    delete (&ClanTree);
    CoinTree.deleteTree();
    delete (&CoinTree);
    MostCoins = NULL;
    BestPlayer = NULL;
}

OasisStatusType Oasis:: addPlayer (int playerID, int initialCoins){
    if(playerID<=0 || initialCoins<0 || this==NULL)
        return OasisINVALID_INPUT;
     Player *newPlayer = new Player(playerID, initialCoins);

     try{
         this->PlayerTree.insert(*newPlayer,this->PlayerTree.getRoot(),PlayerCompByID);
     } catch (TreeMemoryProblemException){
         delete(newPlayer);
         return OasisALLOCATION_ERROR;
     } catch (TreeDataAlreadyExists){
         delete (newPlayer);
         return OasisFAILURE;
     }

    Coins *newCoins = new Coins(initialCoins, playerID, newPlayer);
    try{
        this->CoinTree.insert(*newCoins,this->CoinTree.getRoot(),CoinsCompFunc);
    } catch (TreeMemoryProblemException){
        delete(newPlayer);
        delete(newCoins);
        return OasisALLOCATION_ERROR;
    }
    return OasisSUCCESS;

}

/*int CMP( Clan Clan1 ,Clan Clan2){

    return  Clan1.getClanSize()-Clan1.getClanSize();
}*/


OasisStatusType Oasis:: addClan(int ClanId){

    if(this==NULL||ClanId<=0)
        return OasisINVALID_INPUT;

    Clan *newClan = new Clan(ClanId);

    try{
        this->ClanTree.insert(*newClan, this->ClanTree.getRoot(), ClanCompByID);
    } catch (TreeMemoryProblemException) {
        return OasisALLOCATION_ERROR;
    } catch (TreeDataAlreadyExists){
        delete (newClan);
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
        player_to_add = this->PlayerTree.find(*dummy, this->PlayerTree.getRoot(), PlayerCompByID);
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
        clan_to_add_to = this->ClanTree.find(*dummy_clan, this->ClanTree.getRoot(), ClanCompByID);
    } catch (TreeNodeDoesNotExit){
        delete(dummy);
        return OasisFAILURE; //clan ID isn't in Oasis
    }
    delete(dummy);
    delete(dummy_clan);
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
    ptr->updateClan(clan_to_add_to->getNodeData());
    if (clan_to_add_to->getNodeData()->getBestPlayer() == NULL) {
        clan_to_add_to->getNodeData()->updateBestPlayer(ptr);
    } else if (ptr->getChallenges() > clan_to_add_to->getNodeData()->getBestPlayer()->getChallenges()) {
        clan_to_add_to->getNodeData()->updateBestPlayer(ptr);
    }
    return OasisSUCCESS;
}

OasisStatusType Oasis:: completeChallange(int playerID, int coins){
    if(playerID<0 || coins<0)
        return OasisINVALID_INPUT;
    Player *dummy = new Player(playerID, 0);
    Tree<Player>::Node* player_to_find;
    try{
        player_to_find = this->PlayerTree.find(*dummy, this->PlayerTree.getRoot(), PlayerCompByID);
    } catch (TreeNodeDoesNotExit){
        delete(dummy);
        return OasisFAILURE; //the player is not in the system.
    }
    switch(updateCoinsTree(playerID, player_to_find->getNodeData()->getNumCoins(), coins, player_to_find->getNodeData())) {
        case (OasisINVALID_INPUT): {
            delete (dummy);
            return OasisINVALID_INPUT;
        }
        case (OasisFAILURE): {
            delete (dummy);
            return OasisFAILURE;
        }
        case (OasisALLOCATION_ERROR): {
            delete (dummy);
            return OasisALLOCATION_ERROR;
        }
        default:
            delete (dummy);
    }
    player_to_find->getNodeData()->completeChallange(coins);
    //we are checking if after updating the number of challenges,we have a new Oasid best player
    if(this->BestPlayer->getChallenges() < player_to_find->getNodeData()->getChallenges())
        this->BestPlayer=player_to_find->getNodeData();

    // if our changed player is now equal in num of challenges to the best, we take the smaller identifier
    else if(this->BestPlayer->getChallenges() == player_to_find->getNodeData()->getChallenges()) {
        if (player_to_find->getNodeData()->getID() < this->BestPlayer->getID())
            this->BestPlayer = player_to_find->getNodeData();
    }

     // DOING THE SAME DAMN THING, BUY THIS TIME ON THE CLAN'S BEST PLAYER

    if(player_to_find->getNodeData()->getClan()->getBestPlayer()->getChallenges() <
            player_to_find->getNodeData()->getChallenges())
        this->BestPlayer=player_to_find->getNodeData();

        // if our changed player is now equal in num of challenges to the best, we take the smaller identifier
    else if(player_to_find->getNodeData()->getClan()->getBestPlayer()->getChallenges()
            == player_to_find->getNodeData()->getChallenges()) {
        if (player_to_find->getNodeData()->getClan()->getBestPlayer()->getID() < this->BestPlayer->getID())
            this->BestPlayer = player_to_find->getNodeData();
    }

    return OasisSUCCESS;
}


OasisStatusType Oasis::getBestPlayer(int clanID, int *playerID){
    if(playerID==NULL || clanID==0)
        return OasisINVALID_INPUT;
    if(clanID<0) {
        if (this->PlayerTree.getSize() <= 0) { //there are no players in the system
            *playerID = -1;
            return OasisSUCCESS;
        }
        *playerID= this->BestPlayer->getChallenges(); // first bullet option
        return OasisSUCCESS;
    }

    Clan *dummy = new Clan(clanID);
    Tree<Clan>::Node *clan_to_find;
        try {
            clan_to_find = this->ClanTree.find(*dummy, this->ClanTree.getRoot(), ClanCompByID);
        }
            catch (TreeNodeDoesNotExit) {
            delete (dummy);
            return OasisFAILURE; //the clan is not in the system.
        }
        if(clan_to_find->getNodeData()->getClanSize()==0) {
            delete (dummy);
            *playerID = -1;
            return OasisSUCCESS; //third bullet option
        }
    Player *Bestplayer = clan_to_find->getNodeData()->getBestPlayer();
        if (Bestplayer == NULL) {
            delete (dummy);
            return OasisFAILURE;
        }
    delete (dummy);
    *playerID = Bestplayer->getID(); //the ID of the best player back to oasis
    return OasisSUCCESS; //third bullet option
}

OasisStatusType Oasis:: getScoreboard(int clanID, int **players, int *numOfPlayers){
    if (clanID == 0 || players == NULL || numOfPlayers == NULL){
        return OasisINVALID_INPUT;
    }
    if (clanID < 0){
        if(this->CoinTree.getSize() == 0){
            *numOfPlayers=0;
            *players=NULL;
            return OasisSUCCESS;
        }
        Coins *players_sorted_coins = (Coins*)malloc(sizeof(Coins*)*this->PlayerTree.getSize());
        if(!players_sorted_coins){
            return OasisALLOCATION_ERROR;
        }
        int index = 0;
        this->CoinTree.moveInOrderToArray(players_sorted_coins, &index, this->CoinTree.getRoot());
        *numOfPlayers = this->CoinTree.getSize();
        *players = (int*)malloc(sizeof(int)*(*numOfPlayers));
        if(!(*players)){
            free(players_sorted_coins);
            return OasisALLOCATION_ERROR;
        }
        for (int i = 0; i < *numOfPlayers; ++i) {
            *players[i] = players_sorted_coins[i].getPlayerId();
        }
        free(players_sorted_coins);
        return OasisSUCCESS;
    }
    Clan *dummy_clan = new Clan(clanID);
    Tree<Clan>::Node* clan_to_display;
    try {
        clan_to_display = this->ClanTree.find(*dummy_clan, this->ClanTree.getRoot(), ClanCompByID);
    } catch (TreeNodeDoesNotExit){
        delete(dummy_clan);
        return OasisFAILURE; //clan ID isn't in Oasis
    }
    delete(dummy_clan);
    Coins *players_sorted_coins = (Coins*)malloc(sizeof(Coins)*this->PlayerTree.getSize());
    if(!players_sorted_coins){
        return OasisALLOCATION_ERROR;
    }
    int index = 0;
    this->CoinTree.moveInOrderToArray(players_sorted_coins, &index, this->CoinTree.getRoot());
    *numOfPlayers = clan_to_display->getNodeData()->getClanSize();
    *players = (int*)malloc(sizeof(int)*(*numOfPlayers));
    if(!(*players)){
        free(players_sorted_coins);
        return OasisALLOCATION_ERROR;
    }
    index=0;
    for (int i = 0; i < this->PlayerTree.getSize(); ++i) {
        if(clanID == players_sorted_coins[i].getClanID()){
            *players[index] = players_sorted_coins[i].getPlayerId();
        }
    }
    free(players_sorted_coins);
    return OasisSUCCESS;
}




OasisStatusType Oasis:: uniteClans(int clanID1, int clanID2){
    if(clanID1<=0 || clanID2<=0)
        return OasisINVALID_INPUT;
    Clan *dummy1 = new Clan(clanID1);
    Tree<Clan>::Node *clan1;
    try {
        clan1 = this->ClanTree.find(*dummy1, this->ClanTree.getRoot(), ClanCompByID);
    }
    catch (TreeNodeDoesNotExit) {
        delete (dummy1);
        return OasisFAILURE; //the clan is not in the system.
    }
    Clan *dummy2 = new Clan(clanID1);
    Tree<Clan>::Node *clan2;
    try {
        clan2 = this->ClanTree.find(*dummy2, this->ClanTree.getRoot(), ClanCompByID);
    }
    catch (TreeNodeDoesNotExit) {
        delete (dummy2);
        delete (dummy1);
        return OasisFAILURE; //the clan is not in the system.
    }

    delete (dummy1);
    delete (dummy2);
    //checking who is the best player od the new joint clan
    Player* safe;
    if(clan1->getNodeData()->getBestPlayer()->getChallenges()==0 &&
       clan2->getNodeData()->getBestPlayer()->getChallenges()==0){
        safe=NULL;
    }
    if(clan1->getNodeData()->getBestPlayer()->getChallenges()== clan2->getNodeData()->getBestPlayer()->getChallenges()&&
        clan1->getNodeData()->getBestPlayer()->getChallenges()!=0) {
        if (clan1->getNodeData()->getBestPlayer()->getID() < clan2->getNodeData()->getBestPlayer()->getID())
            safe = clan1->getNodeData()->getBestPlayer();
        else
            safe = clan2->getNodeData()->getBestPlayer();
    }
    else if(clan1->getNodeData()->getBestPlayer()->getChallenges() < clan2->getNodeData()->getBestPlayer()->getChallenges()){
        safe=clan2->getNodeData()->getBestPlayer();}
     else
        safe=clan1->getNodeData()->getBestPlayer();

    //on this point we have clan1 and clan2 themselves.
    if(clan1->getNodeData()->getClanSize() == clan2->getNodeData()->getClanSize()){
        if(clanID1<clanID2) {
            clan1->getNodeData()-> updateBestPlayer(safe);
            if(clan1->getNodeData()->ClanSwalalala(clan2->getNodeData())==ClanALLOCATION_ERROR)
                return OasisALLOCATION_ERROR;
            return OasisSUCCESS;
        }
         else
            clan2->getNodeData()-> updateBestPlayer(safe);
            if(clan2->getNodeData()->ClanSwalalala(clan1->getNodeData())==ClanALLOCATION_ERROR)
              return OasisALLOCATION_ERROR;
            return OasisSUCCESS;
        }
    else if (clan1->getNodeData()->getClanSize() < clan2->getNodeData()->getClanSize()){
            clan2->getNodeData()-> updateBestPlayer(safe);
            if(clan2->getNodeData()->ClanSwalalala(clan1->getNodeData())==ClanALLOCATION_ERROR)
                return OasisALLOCATION_ERROR;
            return OasisSUCCESS;
    }
          else
            clan1->getNodeData()-> updateBestPlayer(safe);
            if(clan1->getNodeData()->ClanSwalalala(clan2->getNodeData())==ClanALLOCATION_ERROR)
                return OasisALLOCATION_ERROR;
            return OasisSUCCESS;

}



OasisStatusType Oasis::updateCoinsTree(int playerID, int oldCoins, int addedCoins, Player* player){
    Coins *dummy = new Coins(oldCoins, playerID, player);
    Tree<Coins>::Node *temp;
    try{
        this->CoinTree.remove(*dummy, CoinsCompFunc);
    } catch (TreeNodeDoesNotExit){
        return OasisFAILURE;
    }
    Coins *coins = new Coins(oldCoins+addedCoins, playerID, player);
    try {
        this->CoinTree.insert(*coins, this->CoinTree.getRoot(), CoinsCompFunc);
    } catch (TreeMemoryProblemException){
        return OasisALLOCATION_ERROR;
    }
    return OasisSUCCESS;
}


//void Oasis::Quit(){}
