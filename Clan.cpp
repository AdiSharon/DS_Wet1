#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"

using DS::DSExceptions;





//c'tor
Player:: Player() {

}

Player:: Player(int ID, int coins){
    this->PlayerID=ID;
    this->Coins=coins;
}


//d'tor
Player::~Player(){



}

//after Oasis has found the clan & player, updates the clan pointer
ClanStatusType Player::updateClan(Tree<Player*>::Node *ClanNode){
    if(!ClanNode)
        return ClanINVALID_INPUT;
    this->ClanNode= ClanNode;
    return ClanSUCCESS;
}

ClanStatusType Player:: completeChallange(int coins){
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


Clan::Clan();


Clan::~Clan();

ClanStatusType Clan::AddPlayerToClan(int PlayerId) {


}

Player* Clan::getBestPlayer(){
    return this->BestPlayer;
}

int Clan:: getClanSize(){
    return this->ClanSize;
}

Player* Clan:: FindPlayerInClanByID(int ID){
    this->ClanPlayersTree.find()

}





