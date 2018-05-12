#include "Tree.h"
#include <iostream>

int cmp (int x, int y){
    return x-y;
}

int main() {
    Tree<int> *t = new Tree<int>;
    t->insert(20, t->getRoot(), cmp);
    t->insert(25, t->getRoot(), cmp);
    t->insert(15, t->getRoot(), cmp);
    t->insert(30, t->getRoot(), cmp);
    t->insert(5, t->getRoot(), cmp);
    t->insert(35, t->getRoot(), cmp);
    t->insert(67, t->getRoot(), cmp);
    t->insert(43, t->getRoot(), cmp);
    t->insert(21, t->getRoot(), cmp);
    t->insert(10, t->getRoot(), cmp);
    t->insert(89, t->getRoot(), cmp);
    t->insert(38, t->getRoot(), cmp);
    t->insert(69, t->getRoot(), cmp);
    try{
        t->insert(10, t->getRoot(), cmp);
    } catch (TreeDataAlreadyExists){
        std::cout <<"got It!" << std::endl;
    }
    t->remove(5, cmp);
    t->remove(35,cmp);
    try{
        t->remove(65,cmp);
    } catch (TreeDataAlreadyExists){
    std::cout <<"got It!" << std::endl;
}
    t->remove(89,cmp);
    t->remove(43,  cmp);
    t->remove(88, cmp);
    t->remove(20,  cmp);
    t->remove(38,  cmp);
    int x = 0;
}