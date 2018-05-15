#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"

using DS::DSExceptions;

//c'tor

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

    try{
    this->ClanPlayersTree.PostOrderRemove(this->ClanPlayersTree.getRoot()
            ,findRemoveFromClan,ClanPlayerCompByID);
    smallClan->ClanPlayersTree.PostOrderRemove(this->ClanPlayersTree.getRoot()
            ,findRemoveFromClan,ClanPlayerCompByID);
        if(this->getClanSize()<=0&&smallClan->getClanSize()<=0){
            return ClanSUCCESS;
        }
    this->ClanPlayersTree.uniteTreesAux(smallClan->ClanPlayersTree,ClanPlayerCompByID);
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


Coins::Coins (int numCoins, int playerID, Player* player):
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
    if(!this->player->getClan()){
        return -1; //player is not in any clan
    }
    return this->player->getClan()->getID();
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

int Coins::getClanID(){
    return this->player->getClan()->getID();
}

