#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"

using DS::DSExceptions;


static int ClanPlayerCompByID(Player *a, Player *b){
    return a->getID()-b->getID();
}

static bool findRemoveFromClan(Player *player){
    if(player->getChallenges()==0){
        player->removeFromClan();
        return true;
    }
    else
        return false;
}


bool Player::operator==(const Player& player) const{
    return player.PlayerID == this->PlayerID;
}

Player& Player::operator=(const Player& player){
    if (*this == player){
        return *this;
    }
    PlayerID = player.PlayerID;
    ClanNode = player.ClanNode;
    CoinHolder = player.CoinHolder;
    Challenges = player.Challenges;
    coins = player.coins;
    clan = player.clan;
    return *this;
}

Player::Player(const Player &player) {
    PlayerID = player.PlayerID;
    ClanNode = player.ClanNode;
    CoinHolder = player.CoinHolder;
    Challenges = player.Challenges;
    coins = player.coins;
    clan = player.clan;
}

bool Clan::operator==(const Clan& clan) const{
    return clan.ClanId == this->ClanId;
}

Clan& Clan::operator=(const Clan& clan){
    if (*this == clan){
        return *this;
    }
    ClanId = clan.ClanId;
    //ClanSize = clan.ClanSize;
    BestPlayer = clan.BestPlayer;
    ClanPlayersTree = clan.ClanPlayersTree;
    return *this;
}

Clan::Clan(const Clan &clan) {
    ClanId = clan.ClanId;
    //ClanSize = clan.ClanSize;
    BestPlayer = clan.BestPlayer;
  //  ClanPlayersTree = clan.ClanPlayersTree;

}

bool Coins::operator==(const Coins& coins) const{
    return coins.playerID == this->playerID;
}

Coins& Coins::operator=(const Coins& coins){
    if (*this == coins){
        return *this;
    }
    numCoins = coins.numCoins;
    playerID = coins.playerID;
    player = coins.player;
    return *this;
}


Coins::Coins(const Coins &coins){
    numCoins = coins.numCoins;
    playerID = coins.playerID;
   player = coins.player;
}

Player:: Player(int ID, int coins){
    this->PlayerID=ID;
    this->Challenges=0;
    this->coins=coins;
    this->clan=NULL;
    this->ClanNode=NULL;
    this->CoinHolder=NULL;
}

//d'tor
Player::~Player(){
    this->CoinHolder=NULL;
    this->ClanNode=NULL;
    this->clan=NULL;
}

//after Oasis has found the clan & player, updates the clan pointer
ClanStatusType Player::updateClanNode(Tree<Player*>::Node *ClanNode){
    if(!ClanNode)
        return ClanINVALID_INPUT;
    this->ClanNode= ClanNode;
    return ClanSUCCESS;
}

ClanStatusType Player:: completeChallange(int coins){
    this->coins+=coins;
    this->Challenges++;
    return ClanSUCCESS;
}

int Player::getID() {
    return this->PlayerID;
}

ClanStatusType Player:: updateCoins(int coins){
    if (coins <= 0){
        return ClanINVALID_INPUT;
    }
    this->coins += coins;
    return ClanSUCCESS;
}

/*
 * if this is greater than other, return >0
 */
/*int Player::compareById(Player other){
    return  - other.PlayerID;
}

int Player::compareByCoin(Player other){
    return this->Coins-other.Coins;
}
*/
Clan* Player:: getClan(){
    if (this==NULL)
        return NULL;
    return this->clan;
}



Clan::Clan(int ClanId){
//    this->ClanSize=0;
    this->ClanId=ClanId;
    this->BestPlayer=NULL;
    this->ClanPlayersTree = Tree<Player*>();
}


Clan::~Clan(){
    this->BestPlayer = NULL;
    this->ClanPlayersTree.deleteTree();
    //delete(ptr);
}

ClanStatusType Clan::AddPlayerToClan(Player* player) {
    if(player==NULL)
        return ClanINVALID_INPUT;
    try{
    this->ClanPlayersTree.insert(player,this->ClanPlayersTree.getRoot(),ClanPlayerCompByID);
    }
    catch (TreeMemoryProblemException){
        return ClanALLOCATION_ERROR;
    }
        catch (TreeDataAlreadyExists){
            return ClanFAILURE;
        }
  //  this->ClanSize++;
    if(this->getBestPlayer()== NULL || this->getBestPlayer()->getChallenges()<player->getChallenges())
    this->updateBestPlayer(player);
    return ClanSUCCESS;
}

Player* Clan::getBestPlayer(){
    return this->BestPlayer;
}

int Clan:: getClanSize(){
    return this->ClanPlayersTree.getSize();
}

int Clan::getID(){
    return this->ClanId;
}


ClanStatusType Clan::ClanSwalalala(Clan *smallClan){
    int my_size = 0, his_size = 0;
    try{
    this->ClanPlayersTree.PostOrderRemove(this->ClanPlayersTree.getRoot()
            ,findRemoveFromClan,ClanPlayerCompByID, &my_size);
    smallClan->ClanPlayersTree.PostOrderRemove(smallClan->ClanPlayersTree.getRoot()
            ,findRemoveFromClan,ClanPlayerCompByID, &his_size);
        if(smallClan->getClanSize()<=0)
            smallClan->updateBestPlayer(NULL);
        if(this->getClanSize()<=0)
            this->updateBestPlayer(NULL);
        Player **small_players = (Player**)malloc( sizeof(Player*)*(smallClan->ClanPlayersTree.getSize()));
        if(!small_players){
            return ClanALLOCATION_ERROR;
        }
        int index = 0;
        smallClan->ClanPlayersTree.moveInOrderToArray(small_players, &index, smallClan->ClanPlayersTree.getRoot());
        for (int i = 0; i < smallClan->ClanPlayersTree.getSize(); ++i) {
            if(!findRemoveFromClan(small_players[i])){
                (*small_players[i]).updateClan(this);
            }
        }
        free(small_players);
    this->ClanPlayersTree.uniteTreesAux(findRemoveFromClan, smallClan->ClanPlayersTree,ClanPlayerCompByID, &my_size, &his_size);
    }
    catch(TreeMemoryProblemException){
        return ClanALLOCATION_ERROR;
    }
   // this->ClanSize=this->ClanPlayersTree.getSize();
    return ClanSUCCESS;
}




int Player::getChallenges() {
    return this->Challenges;

}


Coins::Coins (int numCoins, int playerID, Tree<Player>::Node *player):
        numCoins (numCoins),
        playerID(playerID),
        player(player){}

Coins::~Coins(){
    this->player = NULL;
}

int Coins::getNumCoins(){
    return this->numCoins;
}

int Coins::getPlayerId(){
    return this->playerID;
}

void Coins::updateCoins(int addedCoins) {
    this->numCoins += addedCoins;
}

int Coins::getCoinsClan(){
    if(!this->player->getNodeData()->getClan()){
        return -1; //player is not in any clan
    }
    return this->player->getNodeData()->getClan()->getID();
}

void Player::removeFromClan(){
    this->clan = NULL;
}

void Player::updateClan(Clan *clan){
    this->clan = clan;
}

void Clan::updateBestPlayer(Player* player){
    this->BestPlayer = player;
}

int Player::getNumCoins(){
    return this->coins;
}

void Clan::upateBestPlayer(Player* player){
    this->BestPlayer = player;
}

int Coins::getClanID(){
    if(this->player->getNodeData()->getClan() != NULL){
        return this->player->getNodeData()->getClan()->getID();
    }
    return -1;
}

Clan* Coins::getCoinsClansClan() {
    return this->player->getNodeData()->getClan();
}
