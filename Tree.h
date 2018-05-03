
#ifndef HW2_TREE_H
#define HW2_TREE_H

#include <iostream>
#include <assert.h>
#include <algorithm>
#include "Execptions.h"

using namespace std;

template <typename T>
class Tree {
    class Node {
        T data; //the data (of a type)
        int height;
        Node *right_son; //the node's right son.
        Node *left_son; //the node's left son.
        Node *father; //the node's father. if node is the root, is null.

        /*!
         * the basic c'tor. constructs a node that contains the basic data.
         * @param data - the actuall type & data of the specific link in the
         * Tree
         */
        Node(const T &data) :
                data(data),
                height(0),
                right_son(NULL),
                left_son(NULL),
                father(NULL) {};

        //Tree needs access to private fields.
        friend class Tree<T>;

    public:

        //default assignment operand.
        Node &operator=(const Node &node) = default;

    };

    int size; //the number of valid nodes in the tree.
    Node  *root; //the first node in the tree.int height;
    int height; //the tree's height.



    static const int HEAD_INDEX = 0; //C++ NULL

public:


    /*!
     * Tree c'tor. creates an empty Tree.
     */
    Tree();

    /*!
     * copy c'tor. constructs a new Tree with given Tree params.
     * @param Tree - the Tree to copy.
     */
    Tree(const Tree &tree);

    /*!
     * a Tree d'to. deletes all the nodes of a given Tree.
     */
    ~Tree();

    /*!
     * an assignment operator
     * @param Tree - the Tree to be assigned.
     * @return ref to a new Tree that contains the assigned values.
     */
    Tree &operator=(const Tree &tree);

    /*!
     * return the number of items in the linked Tree.
     * @return - the int number of items.
     */
    int getSize() const;

    /*!
     * function adds a new item to the Tree with the data value.
     * inserts at the Tree's end.
     * @param data - the new item's data.
     */
    void insert(const T &data);

    /*!
     * functions sorts the Tree according to the given Compare function.
     * @tparam Compare - function object. returns true if first param is before
     *                   second param.
     * @param compare - the compare function
     */
    template <typename Compare>
    void rotateRight(const Compare &compare);

    /*!
     * functions sorts the Tree according to the given Compare function.
     * @tparam Compare - function object. returns true if first param is before
     *                   second param.
     * @param compare - the compare function
     */
    template <typename Compare>
    void rotateLeft(const Compare &compare);

    /*!
     * checks if two Trees are equal.
     * @param Tree - the right hand Tree to compare to.
     * @return true if both Trees contains the same items at the same order.
     */
    bool operator==(const Tree &tree) const;

    /*!
     * check if two Trees are NOT equal/
     * @param Tree - the right hand Tree to compare to.
     * @return the ! of ==.
     */
    bool operator!=(const Tree &tree) const;

    /*!
     * ///////////////////////////////////////////
     * @param Tree - the right hand Tree to compare to.
     * @return the ! of ==.
     */
    bool operator>(const Tree &tree) const;

    /*!
     * ///////////////////////////////////////////
     * @param Tree - the right hand Tree to compare to.
     * @return the ! of ==.
     */
    bool operator<(const Tree &tree) const;


};

template <class T>
Tree<T>::Tree() :
        size(HEAD_INDEX),
        root (NULL),
        height(HEAD_INDEX){}


/*template <class T>
Tree<T>::Tree(const Tree& Tree) :
        size(HEAD_INDEX),
        root(NULL){
    for(Node *current = Tree.root; current != NULL;
        current = current->){
        insert(current->data);
    }
}*/

template <class T>
Tree<T>::~Tree() {
    Node *node = root;
    if (node != NULL){
        delete(node);
    }
    delete(this);
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree& tree) {
    if (this == &tree){
        return *this;
    }
    delete(this->root);
    this->root=tree.root;
    this->height=tree.height;
    this->size=tree.size;
    return *this;
}

template <class T>
int Tree<T>::getSize() const {
    return this->size;
}


/*template <class T>
typename Tree<T>::Iterator Tree<T>::end() const {
    return Iterator(this, Tree_end);
}*/

template <class T>
void Tree<T>::insert(const T &data) {
    Tree::Node *new_node= new Tree::Node(data);

}

template <class T>
void Tree<T>::insert(const T &data) {
    Node *newNode = new Node(data);
    if(size == 0){
        Tree_head = newNode;
        newNode->previous = NULL;
        newNode->next = NULL;
        size++;
        return;
    }
    Node *current = Tree_head;
    while (current->next != Tree_end){
        current = current->next;
    }
    current->next = newNode;
    newNode->previous = current;
    size++;
}

template <class T>
void Tree<T>::remove(Iterator iterator) {
    if (size == 0 || this != iterator.Tree){
        throw ElementNotFound();
    }
    Node *current = Tree_head;
    while (current->data != iterator.current->data && current != Tree_end){
        current = current->next;
    }
    if(current == Tree_end){
        throw ElementNotFound();
    }
    if(iterator.current->previous != NULL){
        (current->previous)->next = current->next;
    }else {
        Tree_head = current->next;
    }
    if(iterator.current->next != NULL){
        (current->next)->previous = current->previous;
    }
    delete(current);
    size--;
}

template <typename T>
template <typename Predicate>
typename Tree<T>::Iterator Tree<T>::find(const Predicate &predicate){
    for(Node *current = Tree_head; current != NULL; current = current->next){
        if(predicate(current->data)){
            return Iterator(this, current);
        }
    }
    return this->end();
}

template <typename T>
template <typename Compare>
void Tree<T>::sort(const Compare &compare){
    if(size == 0 || size == 1){ //no sort needed
        return;
    }
    Node *current = Tree_head;
    Tree<T> sorted;
    bool added = false;
    sorted.insert(Tree_head->data);
    current = current->next;
    while (current){
        added = false;
        Node* other = sorted.Tree_head;
        for (int i = 0; i < sorted.size; ++i) {
            if(compare(current->data, other->data) == true){
                Iterator insert(&sorted, other);
                sorted.insert(current->data, insert);
                added = true;
                break;
            }
            other = other->next;
        }
        if(!added){
            sorted.insert(current->data);
        }
        if(current->next != NULL){
            current = current->next;
        } else {
            break;
        }
    }
    int length = this->size;
    for (int l = 0; l < length; ++l) {
        this->remove(this->begin());
    }
    *this = sorted;
}

template <class T>
bool Tree<T>::operator==(const Tree& Tree) const{
    bool same = (this->size == Tree.size);
    if (same){
        Node *other = Tree.Tree_head;
        Node *current = Tree_head;
        while (current){
            assert(other != Tree.Tree_end); //we checked that the Tree are
            // of the same size.
            if (other->data != current->data){
                same = false;
                break;
            }
            if(other->next != NULL){
                other = other->next;
                current = current->next;
            } else if (current->next != NULL){
                same = false;
                break;
            } else{
                current = NULL;
            }
        }
    }
    return same;
}

template <class T>
bool Tree<T>::operator!=(const Tree& Tree) const{
    return !(*this == Tree);
}


template <class T>
T& Tree<T>::Iterator::operator*() const {
    if(current == NULL){
        throw ElementNotFound();
    }
    return current->data;
}

template <class T>
typename Tree<T>::Iterator& Tree<T>::Iterator::operator++() {
    if(current != NULL){
        current = current->next;
    }
    return *this;
}

template <class T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator++(int) {
    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
typename Tree<T>::Iterator& Tree<T>::Iterator::operator--() {
    if(current->previous != NULL){
        current = current->previous;
    }
    return *this;
}

template <class T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator--(int) {
    Iterator result = *this;
    --*this;
    return result;
}

template <class T>
bool Tree<T>::Iterator::operator==(const Iterator& iterator) const{
    if(current == this->Tree->Tree_end &&
       iterator.current == iterator.Tree->Tree_end){
        return (Tree == iterator.Tree);
    } else if (current != this->Tree->Tree_end &&
               iterator.current != iterator.Tree->Tree_end){
        return (Tree == iterator.Tree &&
                current->data == iterator.current->data);
    } else {
        return false;
    }
}

template <class T>
bool Tree<T>::Iterator::operator!=(const Iterator& iterator) const{
    return !(*this == iterator);
}


#endif //HW2_TREE_H
