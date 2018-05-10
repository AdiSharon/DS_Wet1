#include <iostream>
#include "Tree.h"
#include <iostream>

int compareInt(int x, int y){
    return x-y;
}

int main() {
    Tree<int> *t = new Tree<int>;

    t->insert(20,t->getRoot(*t),compareInt);
    t->insert(25,t->getRoot(*t),compareInt);
    t->insert(15,t->getRoot(*t),compareInt);
    t->insert(30,t->getRoot(*t),compareInt);
    t->insert(5,t->getRoot(*t),compareInt);
    t->insert(35,t->getRoot(*t),compareInt);
    t->insert(67,t->getRoot(*t),compareInt);
    t->insert(43,t->getRoot(*t),compareInt);
    t->insert(21,t->getRoot(*t),compareInt);
    t->insert(10,t->getRoot(*t),compareInt);
    t->insert(89,t->getRoot(*t),compareInt);
    t->insert(38,t->getRoot(*t),compareInt);
    t->insert(69,t->getRoot(*t),compareInt);
    t->insert(10,t->getRoot(*t),compareInt);
    t->remove(5,compareInt);
    t->remove(35,compareInt);
    t->remove(65,compareInt);
    t->remove(89,compareInt);
    t->remove(43,compareInt);
    t->remove(88,compareInt);
    t->remove(20,compareInt);
    t->remove(38, compareInt);
}