#include "library1.h"
#include "Oasis.h"

void* init(){
    Oasis* DS = new Oasis();
    return (void*)DS;
}


StatusType addPlayer(void *DS, int playerID, int initialCoins){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->addPlayer(playerID,initialCoins);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType addClan(void *DS, int clanID){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->addClan(clanID);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType joinClan(void *DS, int playerID, int clanID) {
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->joinClan(playerID,clanID);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType getBestPlayer(void *DS, int clanID, int *playerID){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->getBestPlayer(clanID,playerID);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
}


StatusType completeChallange(void *DS, int playerID, int coins){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->completeChallange(playerID,coins);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;

}

StatusType getScoreboard(void *DS, int clanID, int **players, int *numOfPlayers){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->getScoreboard(clanID,players,numOfPlayers);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType uniteClans(void *DS, int clanID1, int clanID2){
    if(DS==NULL)
        return INVALID_INPUT;
    OasisStatusType Answer= ((Oasis*)DS)->uniteClans(clanID1,clanID2);
    switch (Answer) {
        case (OasisINVALID_INPUT):
            return INVALID_INPUT;
        case (OasisFAILURE):
            return FAILURE;
        case (OasisALLOCATION_ERROR):
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

void quit(void** DS){
    Oasis **system = (Oasis**)DS;
    delete (*system);
}




