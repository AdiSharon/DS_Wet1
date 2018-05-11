//
// Created by Adi Sharon on 5/1/2018.
//

#ifndef EXECPTIONS_H
#define EXECPTIONS_H

#include <stdexcept>

namespace DS {

    class DSExceptions {};

    namespace Oasis {

        class OasisException : public DSExceptions {};
        class OasisMemoryProblemException : public OasisException {};
        class OasisInvalidInputException : public OasisException {};
        class OasisFailureException : public OasisException {};

    }

    namespace Tree {
        class TreeExceptions : public DSExceptions {};
        class TreeMemoryProblemException : public TreeExceptions {};
        class TreeInvalidInput : public TreeExceptions {};
        class TreeDataAlreadyExists : public TreeExceptions {};
        class TreeNodeDoesNotExit : public TreeExceptions {};
        class TreeBFProblem : public TreeExceptions {};
        class TreeSuccess : public TreeExceptions {};


    }


}


#endif //EXECPTIONS_H
