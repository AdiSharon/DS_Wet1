#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"

using DS::DSExceptions;

//c'tor

Player:: Player(int ID, int coins){
    this->PlayerID=ID;
    this->Challenges=0;
    this->Coins=coins;
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
    if(this->PlayerID<0 || coins<0)
        return ClanINVALID_INPUT;
    this->Coins+=coins;
    return ClanSUCCESS;
}

ClanStatusType Player:: updateCoins(Tree<Player*>::Node *CoinHolder){


}

/*
 * if this is greater than other, return >0
 */
int Player::compareById(Player other){
    return this->PlayerID - other.PlayerID;
}

int Player::compareByCoin(Player other){
    return this->Coins-other.Coins;
}

Clan* Player:: getClan(){
    if (this==NULL)
        return NULL;
    return this->clan;
}



Clan::Clan(int ClanId){
    this->ClanSize=0;
    this->ClanId=ClanId;
    this->BestPlayer=NULL;
    this->ClanPlayersTree=NULL;
}


Clan::~Clan(){
}




ClanStatusType Clan::AddPlayerToClan(Player* player) {
    if(player==NULL)
        return ClanINVALID_INPUT;
    try{
    this->ClanPlayersTree.insert(player,this->ClanPlayersTree.getRoot(this->ClanPlayersTree),PlayerCompByID::operator());}
    catch (TreeMemoryProblemException){
        return ClanALLOCATION_ERROR;
    }
        catch (TreeDataAlreadyExists){
            return ClanINVALID_INPUT;
        }
    return ClanSUCCESS;
}

Player* Clan::getBestPlayer(){
    return this->BestPlayer;
}

int Clan:: getClanSize(){
    return this->ClanSize;
}






