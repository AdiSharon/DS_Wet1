#include "Oasis.h"
#include "library1.h"


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
    statusType = addClan(oasis,11);
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

    statusType = addClan(oasis,11);
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



    statusType = addClan(oasis,0);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND CLAN WITH BAD ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    statusType = addClan(oasis,-3);
    switch (statusType) {
        case (INVALID_INPUT):
            std::cout << "INVALID INPUT" << std::endl;
            break;
        case (SUCCESS):
            std::cout << "IT SUCCSSEDED THOUGH IT SHOULDNT HAVE. PROBLEM WITH ADDIND CLAN WITH BAD ID"
                      << std::endl;
            break;
        case (ALLOCATION_ERROR):
            std::cout << "ALLOC" << std::endl;
            break;
        case (FAILURE):
            std::cout << "ALL GOOD! DIDNT ADD IT AS IT SHOULD HAVE" << std::endl;
            break;
    }


    statusType = addClan(oasis,12);
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
            std::cout << "clan 12 added" << std::endl;
            break;
    }
    statusType = addClan(oasis,13);
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
            std::cout << "clan 13 added" << std::endl;
            break;
    }





}

