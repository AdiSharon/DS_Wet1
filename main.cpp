
#include "Tree.h"
#include <vector>
#include <ostream>
#include <algorithm>

class intComp {
public:
    // returns negative,0,positive if ID of c1 is less,equal,greater than of c2
    //int operator()(const int& x, const int& y) const {
    //	return x-y;
    //}

    // returns negative,0,positive if ID of c is less,equal,greater than i
    int operator()(int x, int ID, int LVL = 0) const {
        return x - ID;
    }

};


int comp(int x, int y){
    return x-y;
}

int main() {
    Tree<int> tree;

    //Specific Cases

    /*correct output for the four next cases
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0 */

    //basic LL root change
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();




    //basic LR root change
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "first check" << std::endl;

    //basic RR root change
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "second check" << std::endl;

    //basic RL root change
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "third check" << std::endl;

    //basic LR not root change
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    4 BF: 1 Height: 2
    5 BF: 0 Height: 0
    6 BF: 1 Height: 3
    7 BF: 0 Height: 0
    8 BF: 1 Height: 1 */
    tree.insert(6,tree.getRoot(tree), comp);
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "fourth check" << std::endl;

    //basic LL not root change
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    4 BF: 1 Height: 2
    5 BF: 0 Height: 0
    6 BF: 1 Height: 3
    7 BF: 0 Height: 0
    8 BF: 1 Height: 1 */
    tree.insert(6,tree.getRoot(tree), comp);
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "fifth check" << std::endl;

    //basic RR not root change
    /*correct output
    * 1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    5 BF: 1 Height: 2
    7 BF: 0 Height: 0*/
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "sixth check" << std::endl;

    //basic RL not root change
    /*correct output
    * 1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    5 BF: 1 Height: 2
    7 BF: 0 Height: 0*/
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "seventh check" << std::endl;


    //root deletion no roll successor is a neighbour
    /*correct output
    2 BF: 0 Height: 0
    3 BF: 1 Height: 1
    5 BF: 1 Height: 2
    6 BF: 0 Height: 0*/
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(6,tree.getRoot(tree), comp);
    tree.remove(4, comp);

    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "eigth check" << std::endl;

    //root deletion no roll successor is not a neighbour
    /*correct output
    2 BF: 0 Height: 0
    3 BF: 1 Height: 1
    5 BF: 0 Height: 2
    6 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0 */
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(6,tree.getRoot(tree), comp);
    tree.remove(4, comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "ninth check" << std::endl;

    //node deletion no roll successor is a neighbour case7
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 1 Height: 1
    4 BF: 1 Height: 2
    5 BF: 0 Height: 0
    7 BF: 1 Height: 3
    8 BF: -1 Height: 1
    9 BF: 0 Height: 0*/
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(9,tree.getRoot(tree), comp);
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.remove(3, comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "tenth check" << std::endl;

    //node deletion no roll successor is not a neighbour case8
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 1 Height: 1
    5 BF: 0 Height: 2
    6 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0
    9 BF: 0 Height: 3
    10 BF: 0 Height: 0
    12 BF: -1 Height: 2
    13 BF: -1 Height: 1
    14 BF: 0 Height: 0*/
    tree.insert(9,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(12,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(10,tree.getRoot(tree), comp);
    tree.insert(13,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(5,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(14,tree.getRoot(tree), comp);
    tree.insert(6,tree.getRoot(tree), comp);
    tree.remove(3, comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "11th check" << std::endl;

    //node deletion causing LR case9
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    4 BF: 0 Height: 2
    7 BF: -1 Height: 1
    8 BF: 0 Height: 0*/
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(9,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.remove(9, comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();

    std::cout << "12th check" << std::endl;

    //node deletion causing LL case10
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 1 Height: 1
    3 BF: 0 Height: 2
    4 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0*/
    tree.insert(7,tree.getRoot(tree), comp);
    tree.insert(3,tree.getRoot(tree), comp);
    tree.insert(8,tree.getRoot(tree), comp);
    tree.insert(2,tree.getRoot(tree), comp);
    tree.insert(4,tree.getRoot(tree), comp);
    tree.insert(9,tree.getRoot(tree), comp);
    tree.insert(1,tree.getRoot(tree), comp);
    tree.remove(9, comp);
    tree.InOrder(tree.getRoot(tree));
    tree.deleteTree();


    std::cout << "donnneeeeeeeee" << std::endl;
    return 0;
}