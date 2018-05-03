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

    namespace TreeExceptions {
        class TreeMemoryProblemException : public std::runtime_error {
            TreeMemoryProblemException() : std::runtime_error("Memory Problem") {}
        };
        class ElementNotFound : public std::runtime_error {
        public:
            ElementNotFound() : std::runtime_error("Element not found") {}
        };

    }


}


#endif //EXECPTIONS_H
