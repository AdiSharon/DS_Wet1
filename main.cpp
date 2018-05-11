#include <iostream>
#include "Tree.h"
#include <string.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>




int compareSring(const char* A,const char* B){
    return strcmp(A,B);
}
/*
 * main.cpp
 *
 *  Created on: May 5, 2017
 *      Author: Omer
 */
void testInsertRemove();

/*
void testNode();
void testDestroySubTree();
void testFindInTree();
void testInsertRemove();
//void testLLRotation();
void testRRRotation();
void testLRRotation();
void testIsASearchTree();
void testIsABalancedTree();
void testTree(); */

int main() {
//	testNode();
//	testDestroySubTree();
//	testFindInTree();
	testInsertRemove();
////	testLLRotation();
//	testRRRotation();
//	testLRRotation();
//	testIsASearchTree();
//	testIsABalancedTree();
    //  testTree();
    return 0;
}

/* void testNode() {
    int data1 = 11;
    int data2 = 22;
    Node<int> node1(key1, data1);
    Node<int> node2(key2, data2);
    node1.linkRightSon(node2);
    //std::cout << "key: " << *(node1.key) << " data: " << *(node1.data) << std::endl;
    std::cout << "father: " << *(node1.key) << ", right son: "
              << *(node1.rightSon->key) << std::endl;
    std::cout << "my father is: " << *(node2.father->key) << std::endl;
}

void testDestroySubTree() {
    Node<int, int>* node1 = new Node<int, int>(1, 11);
    Node<int, int>* node2 = new Node<int, int>(2, 22);
    Node<int, int>* node3 = new Node<int, int>(3, 33);
    node1->linkLeftSon(*node2);
    node1->linkRightSon(*node3);
    node1->destroySubTree();
}

void testFindInTree() {
    Node<int, int>* node1 = new Node<int, int>(1, 11);
    Node<int, int>* node2 = new Node<int, int>(2, 22);
    Node<int, int>* node3 = new Node<int, int>(3, 33);
    Node<int, int>* node4 = new Node<int, int>(4, 44);
    node2->linkLeftSon(*node1);
    node2->linkRightSon(*node3);
    node3->linkRightSon(*node4);
    std::cout << "root: " << *(node2->key) << std::endl;
    std::cout << "left son: " << *(node2->leftSon->key) << std::endl;
    std::cout << "right son: " << *(node2->rightSon->key) << std::endl;
    std::cout << "leaf: " << *(node2->rightSon->rightSon->key) << std::endl;
    for (int i = 1; i < 5; i++) {
        Node<int, int>* node = node2->find(i);
        std::cout << i << ": " << *(node->key) << std::endl;
    }
    std::cout << "should print 4: " << *((node2->find(5))->key) << std::endl;
    std::cout << "should print 1: " << *((node2->find(0))->key) << std::endl;
    node2->destroySubTree();
} */

void testInsertRemove() {
   Tree<const char*> tree;

    //test insert
    tree.insert("huclid",tree.getRoot(tree),compareSring);
    tree.insert("california",tree.getRoot(tree),compareSring);
    tree.insert("kenny",tree.getRoot(tree),compareSring);
    tree.insert("beni",tree.getRoot(tree),compareSring);
    tree.insert("denver",tree.getRoot(tree),compareSring);
    tree.insert("jamaica",tree.getRoot(tree),compareSring);
    tree.insert("year",tree.getRoot(tree),compareSring);
    tree.insert("avi",tree.getRoot(tree),compareSring);
    tree.insert("france",tree.getRoot(tree),compareSring);
    tree.insert("israel",tree.getRoot(tree),compareSring);
    tree.insert("maayan",tree.getRoot(tree),compareSring);
    tree.insert("zoo",tree.getRoot(tree),compareSring);
    tree.insert("lord",tree.getRoot(tree),compareSring);
    tree.InOrder(tree.getRoot(tree));

    //check LLRotation/
    tree.insert("lama",tree.getRoot(tree),compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    //check LRRotation
    tree.insert("noah",tree.getRoot(tree),compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));


    //check RRRotation
    tree.insert("omer",tree.getRoot(tree),compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    //check RLRotation
    tree.insert("krap",tree.getRoot(tree),compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    tree.insert("kip",tree.getRoot(tree),compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    /* inserting an existing key
    try {
        tree.insert("kip",tree.getRoot(tree),compareSring);
    } catch (Tree<std::string>::ElementAlreadyExists& e) {
        std::cout << "caught the exception!" << std::endl;
    } */

    //test remove
    tree.remove("france",compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    tree.remove("kenny",compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    tree.remove("jamaica",compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    tree.remove("avi",compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    tree.remove("israel", compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));

    tree.remove("beni",compareSring);
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    tree.InOrder(tree.getRoot(tree));
}

//void testLLRotation() {
//	Node* node1 = new Node(0, 11);
//	Node* node2 = new Node(1, 22);
//	Node* node3 = new Node(2, 33);
//	Node* node4 = new Node(3, 44);
//	Node* node5 = new Node(25, 44);
//	node1->linkRightSon(*node4);
//	node4->linkLeftSon(*node3);
//	node3->linkLeftSon(*node2);
//	node3->linkRightSon(*node5);
//	node1->h_right = 3;
//	node4->h_left = 2;
//	node3->h_left = 1;
//	node3->h_right = 1;
//	node1->printSubTreeWithSonsInOrder();
//	node4->LLRotation();
//	std::cout << std::endl;
//	std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
//	node1->printSubTreeWithSonsInOrder();
//	std::cout << std::endl;
//	std::cout << "0 height: " << node1->height() << std::endl;
//	std::cout << "1 height: " << node2->height() << std::endl;
//	std::cout << "2 height: " << node3->height() << std::endl;
//	std::cout << "25 height: " << node5->height() << std::endl;
//	std::cout << "3 height: " << node4->height() << std::endl;
//}

/*void testRRRotation() {

    Node<int, int>* n5 = new Node<int, int>(5, 11);
    Node<int, int>* n6 = new Node<int, int>(6, 11);
    Node<int, int>* n7 = new Node<int, int>(7, 22);
    Node<int, int>* n8 = new Node<int, int>(8, 33);
    Node<int, int>* n9 = new Node<int, int>(9, 44);
    Node<int, int>* n10 = new Node<int, int>(10, 44);

    n6->linkLeftSon(*n5);
    n6->linkRightSon(*n8);
    n8->linkLeftSon(*n7);
    n8->linkRightSon(*n9);
    n9->linkRightSon(*n10);

    n10->updateHeight();
    n7->updateHeight();
    n9->updateHeight();
    n5->updateHeight();
    n8->updateHeight();
    n6->updateHeight();
    n6->printSubTreeWithSonsInOrder();

    n6->RRRotation();
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    n8->printSubTreeWithSonsInOrder();
    n8->LLRotation();
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    n6->printSubTreeWithSonsInOrder();

    n6->destroySubTree();
}

void testLRRotation() {
    Node<int, int>* n0 = new Node<int, int>(0, 11);
    Node<int, int>* n1 = new Node<int, int>(1, 11);
    Node<int, int>* n2 = new Node<int, int>(2, 11);
    Node<int, int>* n3 = new Node<int, int>(3, 22);
    Node<int, int>* n4 = new Node<int, int>(4, 33);
    Node<int, int>* n5 = new Node<int, int>(5, 44);
    Node<int, int>* n6 = new Node<int, int>(6, 44);
    Node<int, int>* n8 = new Node<int, int>(8, 44);
    Node<int, int>* n9 = new Node<int, int>(9, 44);
    Node<int, int>* n10 = new Node<int, int>(10, 44);

    n1->linkLeftSon(*n0);
    n8->linkLeftSon(*n2);
    n8->linkRightSon(*n9);
    n2->linkLeftSon(*n1);
    n2->linkRightSon(*n5);
    n9->linkRightSon(*n10);
    n5->linkRightSon(*n6);
    n5->linkLeftSon(*n4);
    n4->linkLeftSon(*n3);

    n0->updateHeight();
    n1->updateHeight();
    n3->updateHeight();
    n6->updateHeight();
    n10->updateHeight();
    n4->updateHeight();
    n5->updateHeight();
    n2->updateHeight();
    n9->updateHeight();
    n8->updateHeight();
    n8->printSubTreeWithSonsInOrder();
    n8->LRRotation();
    std::cout << std::endl;
    std::cout << " ...... The Tree After The Rotation: ......" << std::endl;
    n5->printSubTreeWithSonsInOrder();

    n5->destroySubTree();
}

void testIsASearchTree() {
    Node<int, int>* n0 = new Node<int, int>(0, 0);
    Node<int, int>* n1 = new Node<int, int>(1, 11);
    Node<int, int>* n2 = new Node<int, int>(2, 11);

    bool isASearchTree = n0->isASearchSubTree();
    std::cout << "should be true: " << isASearchTree << std::endl;
    n2->linkLeftSon(*n0);
    isASearchTree = n2->isASearchSubTree();
    std::cout << "should be true: " << isASearchTree << std::endl;
    n2->linkRightSon(*n1);
    isASearchTree = n2->isASearchSubTree();
    std::cout << "should be false: " << isASearchTree << std::endl;
    n2->printSubTreeWithSonsInOrder();
    std::cout << std::endl;
    n2->destroySubTree();

    AVL<int, int> tree;
    tree.insert(1, 1);
    tree.insert(2, 2);
    tree.insert(3, 3);
    tree.insert(4, 4);
    tree.insert(5, 5);
    tree.insert(6, 6);
    tree.insert(7, 7);

    tree.printTreeInOrder();
    std::cout << "should be true: " << tree.isASearchTree() << std::endl;
}

void testIsABalancedTree() {
    Node<int, int>* n0 = new Node<int, int>(0, 0);
    Node<int, int>* n1 = new Node<int, int>(1, 11);
    Node<int, int>* n2 = new Node<int, int>(2, 11);
    //	Node<int, int>* n3 = new Node<int, int>(3, 22);
    //	Node<int, int>* n4 = new Node<int, int>(4, 33);
    //	Node<int, int>* n5 = new Node<int, int>(5, 44);

    bool isABalancedTree = n0->isABalancedSubTree();
    std::cout << "should be true: " << isABalancedTree << std::endl;
    n2->linkLeftSon(*n1);
    n1->linkLeftSon(*n0);
    n0->height = 1;
    n1->height = 2;
    n2->height = 3;
    isABalancedTree = n2->isABalancedSubTree();
    std::cout << "should be false: " << isABalancedTree << std::endl;

    n2->destroySubTree();

    AVL<int, int> tree;
    tree.insert(22, 1);
    tree.insert(12, 2);
    tree.insert(1, 3);
    tree.insert(4, 4);
    tree.insert(30, 5);
    tree.insert(17, 6);
    tree.insert(2, 7);

    isABalancedTree = tree.isABalancedTree();
    std::cout << "should be true: " << isABalancedTree << std::endl;
} *

void testTree() {
    AVL<int, int> tree;
    int* array = new int[1000];
    for (int i = 0; i < 1000; i++) {
        array[i] = i;
    }
    std::random_shuffle(&array[0], &array[999]);
    bool isBalanced = true;
    bool isASearchTree = true;
    for (int i = 0; i < 1000; i++) {
        tree.insert(array[i], 1);
        isBalanced = tree.isABalancedTree();
        isASearchTree = tree.isASearchTree();
        if (!isBalanced || !isASearchTree) {
            std::cout << "problem in iterarion: " << i << std::endl;
        }
    }

    int* array2 = new int[500];
    for (int i = 0; i < 500; i++) {
        array2[i] = 2 * i;
    }
    std::random_shuffle(&array2[0], &array2[499]);
    for (int i = 0; i < 28; i++) {
        tree.remove(array2[i]);
        isBalanced = tree.Balance();
        if (!Balance ) {
            std::cout << "problem in iterarion: " << i << std::endl;

        std::cout << "isBalanced: " << isBalanced << std::endl;
        std::cout << "isASearchTree: " << isASearchTree << std::endl;
    }

    tree.printTreeInOrder();

}
*/