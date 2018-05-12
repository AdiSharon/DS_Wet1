#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"

using DS::DSExceptions;

//c'tor

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
ClanStatusType Player::updateClan(Tree<Player*>::Node *ClanNode){
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
    this->ClanSize=0;
    this->ClanId=ClanId;
    this->BestPlayer=NULL;
    this->ClanPlayersTree = *(new Tree<Player*>());
}


Clan::~Clan(){
    this->BestPlayer = NULL;
    this->ClanPlayersTree.deleteTree();
    delete(this->ClanPlayersTree);
}

ClanStatusType Clan::AddPlayerToClan(Player* player) {
    if(player==NULL)
        return ClanINVALID_INPUT;
    try{
    this->ClanPlayersTree.insert(player,this->ClanPlayersTree.getRoot(),PlayerCompByID::operator());}
    catch (TreeMemoryProblemException){
        return ClanALLOCATION_ERROR;
    }
        catch (TreeDataAlreadyExists){
            return ClanFAILURE;
        }
    this->ClanSize++;
    return ClanSUCCESS;
}

Player* Clan::getBestPlayer(){
    return this->BestPlayer;
}

int Clan:: getClanSize(){
    return this->ClanSize;
}

int Clan::getID(){
    return this->ClanId;
}


ClanStatusType Clan:: ClanSwalalala(Clan smallClan){


    smallClan.ClanPlayersTree.InOrder(smallClan.ClanPlayersTree.getRoot()));



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

