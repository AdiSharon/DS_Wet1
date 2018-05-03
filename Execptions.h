//
// Created by Adi Sharon on 5/1/2018.
//

#ifndef EXECPTIONS_H
#define EXECPTIONS_H

#include <stdexcept>
namespace DS {

    class DSExceptions {};

    namespace TreeExceptions {
        class TreeMemoryProblemException : public DSExceptions {};
        class ElementNotFound : public std::runtime_error {
        public:
            ElementNotFound() : std::runtime_error("Element not found") {}
        };

    }
}


#endif //EXECPTIONS_H
