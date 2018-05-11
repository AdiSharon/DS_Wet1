

#ifndef WET1_OASIS_H
#define WET1_OASIS_H
#include "Execptions.h"
#include <iostream>
#include "Tree.h"
#include "Clan.h"
#include "library1.h"


typedef enum {
    OasisSUCCESS = 0,
    OasisFAILURE = -1,
    OasisALLOCATION_ERROR = -2,
    OasisINVALID_INPUT = -3
} OasisStatusType;


using std::iostream;

class Oasis{
    Tree<Player> PlayerTree;
    Tree<Clan> ClanTree;
    Tree<Player*> CoinTree;
    Player *MostCoins;
    Player *BestPlayer;


 public:

    // c'tor
    Oasis();

    // d'tor
    ~Oasis();

    //if you throw it, we'll catch it!!!
    OasisStatusType addPlayer (int playerID, int initialCoins);

    int CMP( Clan Clan1 ,Clan Clan2);

    OasisStatusType addClan(int ClanId);



    OasisStatusType joinClan(int playerID, int ClanID);

    OasisStatusType completeChallange (int playerID, int coins);

    OasisStatusType getBestPlayer(int clanID, int *playerID);

    OasisStatusType getScoreboard(int clanID, int **players, int *numOfPlayers);

    OasisStatusType uniteClans(int clanID1, int clanID2);

    void Quit();



};



#endif //WET1_OASIS_H
