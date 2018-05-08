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
        class TreeMemoryProblemException : public std::runtime_error {
            TreeMemoryProblemException() : std::runtime_error("ALLOCATION_ERROR") {}
        };
        class TreeElementNotFound : public std::runtime_error {
        public:
            TreeElementNotFound() : std::runtime_error("FAILURE") {}
        };
        class TreeElementExists : public std::runtime_error {
        public:
            TreeElementExists() : std::runtime_error("FAILURE") {}
        };
        class TreeInvalidInput : public std::runtime_error {
        public:
            TreeInvalidInput() : std::runtime_error("INVALID_INPUT") {}
        };
        class TreeExceptions : public DSExceptions {};
        class TreeBFProblem : public TreeExceptions {};

    }


}


#endif //EXECPTIONS_H
