#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library1.h"
#include <iostream>

int main() {


    StatusType statusType;
    void *oasis = init();
    if (oasis != NULL)
        std::cout << "oasis exists" << std::endl;
    else
        std::cout << "real prob, couldnt create system" << std::endl;

    std::cout << "TEST STARTS RIGHT HERE. FIRST ONE" << std::endl;
    std::cout << "" << std::endl;

    statusType = addPlayer(oasis, 1, 1);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "1 ADDED" << std::endl;
            break;
    }

    std::cout << "2ND TEST" << std::endl;
    std::cout << "" << std::endl;

    statusType = addPlayer(oasis, 2, 2);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "2 ADDED" << std::endl;
            break;

    }

    std::cout << "3RD TEST" << std::endl;
    std::cout << "" << std::endl;
    statusType = addPlayer(oasis, 1, 10);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND PLAYER WITH EXISTING ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    std::cout << "4TH TEST" << std::endl;
    std::cout << "" << std::endl;


    statusType = addPlayer(oasis, 2, 10);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND PLAYER WITH EXISTING ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    std::cout << "5TH TEST" << std::endl;
    std::cout << "" << std::endl;


    statusType = addPlayer(oasis, -1, 10);
    switch (statusType) {
        case (FAILURE):
            std::cout << "FAILED. WONDER WHY" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ILLEGAL ID OR COINS"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    std::cout << "6TH TEST" << std::endl;
    std::cout << "" << std::endl;


    statusType = addPlayer(oasis, 0, 10);
    switch (statusType) {
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND PLAYER WITH BAD ID OR COINS"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    std::cout << "7TH TEST" << std::endl;
    std::cout << "" << std::endl;


    statusType = addPlayer(oasis, 123, -1);
    switch (statusType) {
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND PLAYER WITH BAD ID OR COINS"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;

    }
    std::cout << "" << std::endl;
    std::cout << "tests for addPlayer" << std::endl;
    std::cout << "" << std::endl;

    statusType = addPlayer(oasis, 3, 3);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "3 ADDED" << std::endl;
            break;
    }
    statusType = addPlayer(oasis, 4, 4);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "4 ADDED" << std::endl;
            break;
    }
    statusType = addPlayer(oasis, 6, 6);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "6 ADDED" << std::endl;
            break;
    }
    statusType = addPlayer(oasis, 5, 5);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "5 ADDED" << std::endl;
            break;
    }

    std::cout << "" << std::endl;
    std::cout << "tests for addClan" << std::endl;
    std::cout << "" << std::endl;

    statusType = addClan(oasis, 11);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "clan 11 added" << std::endl;
            break;
    }

    statusType = addClan(oasis, 11);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND CLAN WITH EXISTING ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    statusType = addClan(oasis, 0);
    switch (statusType) {
        case (FAILURE):
            std::cout << "FAILED.WONDER WHY" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND CLAN WITH BAD ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    statusType = addClan(oasis, -3);
    switch (statusType) {
        case (FAILURE):
            std::cout << "FAILED. WONDER WHY" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND CLAN WITH BAD ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    statusType = addClan(oasis, 12);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "clan 12 added" << std::endl;
            break;
    }
    statusType = addClan(oasis, 13);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "clan 13 added" << std::endl;
            break;
    }

    std::cout << "" << std::endl;
    std::cout << "tests for joinClan" << std::endl;
    std::cout << "" << std::endl;

    statusType = joinClan(oasis,1,11);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "player 1 added to clan 11" << std::endl;
            break;
    }

    statusType = joinClan(oasis,2,12);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "player 2 added to clan 12" << std::endl;
            break;
    }

    statusType = joinClan(oasis,3,13);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "player 3 added to clan 13" << std::endl;
            break;
    }

    statusType = joinClan(oasis,1,13);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN PLAYER ALREADY IN ANOTHER CLAN" << std::endl;
            break;
    }

    statusType = joinClan(oasis, 4, 89);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN CLANID IS WRONG" << std::endl;
            break;
    }
    statusType = joinClan(oasis, 9, 2);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN PLAYERID IS WRONG" << std::endl;
            break;
    }

    statusType = joinClan(oasis, 4, 0);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT\"" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED.WONDER WHY" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN CLANID IS WRONG" << std::endl;
            break;
    }

    statusType = joinClan(oasis, 4, -6);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT\"" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED.WONDER WHY" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN CLANID IS WRONG" << std::endl;
            break;
    }


    statusType = joinClan(oasis, 0, 3);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED.WONDER WHY" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN PLAYERID IS WRONG" << std::endl;
            break;
    }
    statusType = joinClan(oasis, -6, 3);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED.WONDER WHY" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN PLAYERID IS WRONG" << std::endl;
            break;
    }

    statusType = joinClan(oasis, 4, 11);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "player 4 added to clan 11" << std::endl;
            break;
    }


    statusType = joinClan(oasis, 5, 11);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "player 5 added to clan 11" << std::endl;
            break;
    }
    statusType = joinClan(oasis, 6, 12);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "player 6 added to clan 12" << std::endl;
            break;
    }


    statusType = joinClan(oasis, 6, 13);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK WHEN PLAYER ALREADY IN ANOTHER CLAN" << std::endl;
            break;
    }







    /*
     std::cout << "" << std::endl;
     std::cout << "tests for CompleteChallenge" << std::endl;
     std::cout << "" << std::endl;

     statusType = completeChallange(oasis, 1, 10);
     switch (statusType) {
         case (INVALID_INPUT):
             std::cout << "INVALID INPUT" << std::endl;
             break;
         case (FAILURE):
             std::cout << "FAILED" << std::endl;
             break;
         case (ALLOCATION_ERROR):
             std::cout << "ALLOC" << std::endl;
             break;
         case (SUCCESS):
             std::cout << "check in debugger if player1 has 11 coins" << std::endl;
             break;
     }
     statusType = completeChallange(oasis, -3, 10);
     switch (statusType) {
         case (INVALID_INPUT):
             std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
             break;
         case (FAILURE):
             std::cout << "FAILED" << std::endl;
             break;
         case (ALLOCATION_ERROR):
             std::cout << "ALLOC" << std::endl;
             break;
         case (SUCCESS):
             std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK BAD ID OR COINS" << std::endl;
             break;
     }

     statusType = completeChallange(oasis, 1, 0);
     switch (statusType) {
         case (INVALID_INPUT):
             std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
             break;
         case (FAILURE):
             std::cout << "FAILED" << std::endl;
             break;
         case (ALLOCATION_ERROR):
             std::cout << "ALLOC" << std::endl;
             break;
         case (SUCCESS):
             std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK BAD ID OR COINS" << std::endl;
             break;

     }
     statusType = completeChallange(oasis, 1, 0);
     switch (statusType) {
         case (INVALID_INPUT):
             std::cout << "INVALID INPUT" << std::endl;
             break;
         case (FAILURE):
             std::cout << "ALL GOOD! YOU DIDNT FALL FOR IT" << std::endl;
             break;
         case (ALLOCATION_ERROR):
             std::cout << "ALLOC" << std::endl;
             break;
         case (SUCCESS):
             std::cout << "NO GOOD, SHOULDNT SUCCEED. CHECK BAD ID THAT ALREADY EXISTS" << std::endl;
             break;
     }

     statusType = completeChallange(oasis, 2, 20);
     switch (statusType) {
         case (INVALID_INPUT):
             std::cout << "INVALID INPUT" << std::endl;
             break;
         case (FAILURE):
             std::cout << "FAILED" << std::endl;
             break;
         case (ALLOCATION_ERROR):
             std::cout << "ALLOC" << std::endl;
             break;
         case (SUCCESS):
             std::cout << "check in debugger if player2 has 22 coins" << std::endl;
             break;

     }

     statusType = completeChallange(oasis, 6, 60);
     switch (statusType) {
         case (INVALID_INPUT):
             std::cout << "INVALID INPUT" << std::endl;
             break;
         case (FAILURE):
             std::cout << "FAILED" << std::endl;
             break;
         case (ALLOCATION_ERROR):
             std::cout << "ALLOC" << std::endl;
             break;
         case (SUCCESS):
             std::cout << "check in debugger if player6 has 66 coins, and the coins-tree" << std::endl;
             break;
     }

     std::cout << "" << std::endl;
     std::cout << "tests for getBestPlayer" << std::endl;
     std::cout << "" << std::endl;




 */

    std::cout << "" << std::endl;
    std::cout << "tests for getScoreBoard" << std::endl;
    std::cout << "" << std::endl;

    statusType = completeChallange(oasis, 6, 60);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (FAILURE):
            std::cout << "FAILED" << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "check in debugger if player6 has 66 coins, and the coins-tree" << std::endl;
            break;
    }

    std::cout << "" << std::endl;
    std::cout << "tests for getBestPlayer" << std::endl;
    std::cout << "" << std::endl;



}



