
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

        //Iterator needs access to private fields.
        friend class Iterator;

    public:

        //default assignment operand.
        Node &operator=(const Node &node) = default;

    };

    int size; //the number of valid nodes in the tree.
    Node  *root; //the first node in the tree.



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
    void sort(const Compare &compare);

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

    /*!
     * class iterator. contains a pointer to current node & a pointer to the
     * Tree for compare porpeses.
     */
    class Iterator {
        Node *current; //points to the current link in the Tree.
        const Tree<T> *Tree; //points to the Tree the iterator belongs to.

        /*!
         * the basic c'tor. constructs a new iterator that points to the given
         * node.
         * @param Tree - the Tree that the iterator points to
         * @param node - the Trees node that the iterator points to.
         */
        Iterator(const Tree<T> *Tree, Node *node) :
                current(node),
                Tree(Tree) {}

        //Tree needs access to private fields.
        friend class Tree<T>;

    public:

        //class Node;

        /*!
         * Dereference. this operator returns the data (of T type) that the
         * iterator points to.
         * @return - the data field of the current node.
         */
        T& operator*() const;

        /*!
         * Advances the iterator by one node (by action end, iterator points to
         * the next node of the Tree)
         * @return - the next node in the Tree.
         */
        Iterator &operator++();

        /*!
         * Advances the iterator by one node (by action end, iterator  points to
         * the next node of the Tree, but return val does not reflect it until
         * line end)
         * @return - pre-action iterator.
         */
        Iterator operator++(int);

        /*!
         * Retracts the iterator by one node (by action end, iterator points to
         * the previous node of the Tree)
         * @return - the previous node in the Tree.
         */
        Iterator &operator--();

        /*!
         * Retracts the iterator by one node (by action end, iterator  points to
         * the previous node of the Tree, but return val does not reflect it
         * until line end)
         * @return - pre-action iterator.
         */
        Iterator operator--(int);

        /*!
         * compare operator. checks if the iterator are equal. two iterators
         * would be considered equal if both are pointing to the same node
         * (or to Tree end) at the same Tree.
         * @param iterator - the right hand operand to compare.
         * @return true  - if the iterators are equal,
         *          false - otherwise.
         */
        bool operator==(const Iterator &iterator) const;

        /*!
         * compare operator. checks if the iterator are equal. two iterators
         * would be considered equal if both are pointing to the same node
         * (or to Tree end) at the same Tree.
         * @param iterator - the right hand operand to compare.
         * @return true  - if the iterators are equal,
         *          false - otherwise.
         */
        bool operator<(const Iterator &iterator) const;

        /*!
         * compare operator. checks if the iterator are equal. two iterators
         * would be considered equal if both are pointing to the same node
         * (or to Tree end) at the same Tree.
         * @param iterator - the right hand operand to compare.
         * @return true  - if the iterators are equal,
         *          false - otherwise.
         */
        bool operator>(const Iterator &iterator) const;

        /*!
         * compare operator. checks if the iterator are NOT equal.
         * @param iterator - the right hand operand to compare.
         * @return the not of the == operator result.
         */
        bool operator!=(const Iterator &iterator) const;

        //default copy operand. fields are basic pointers.
        Iterator(const Iterator &iterator) = default;

        //default assignment operand.
        Iterator &operator=(const Iterator &iterator) = default;

    };

    /*!
     * function adds a new item to the Tree with the data value.
     * inserts before given iterator.
     * @param data - the new item's data.
     * @param iterator - the iterator to insert begore.
     *
     * @exception ElementNotFound in case that the given iterator is of another
     *              Tree.
     */
    void insert(const T &data, Iterator iterator);

    /*!
     * function removes an item off the Tree.
     * @param iterator - points to the item to remove.
     *
     * @exception ElementNotFound in case that the given iterator is of another
     *              Tree, or iterator points to the Tree's end.
     */
    void remove(Iterator iterator);

    /*!
     * return the Iterator to the Tree head.
     * @return the Tree head node data (the first item on the Tree.
     */
    Iterator begin() const;

    /*!
     * returns the iterator the Tree end.
     * iterator will point to NULL by the function's end.
     * @return NULL iterator
     */
    Iterator end() const;

    /*!
     * function finds an item in the Tree the fits the Predicate critiria.
     * @tparam Predicate - function object. returns true if an item fits.
     * @param predicate - the function object.
     * @return the iterator value of the first item that fits.
     * if no items fit, returns the Tree end.
     */
    template <typename Predicate>
    Iterator find(const Predicate &predicate);

};

template <class T>
Tree<T>::Tree() :
        size(HEAD_INDEX),
        root (NULL)
/*Tree_iterator(this, Tree_head)*/{}


template <class T>
Tree<T>::Tree(const Tree& Tree) :
        size(HEAD_INDEX),
        root(NULL){
    for(Node *current = Tree.root; current != NULL;
        current = current->){
        insert(current->data);
    }
}

template <class T>
Tree<T>::~Tree() {
    Node *node = Tree_head;
    while (node != NULL){
        Node *next = node->next;
        delete node;
        node = next;
    }
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree& Tree) {
    if (this == &Tree){
        return *this;
    }
    int length = this->size;
    for (int l = 0; l < length; ++l) {
        this->remove(this->begin());
    }
    //Tree_head = current;
    for(Node* current = Tree.Tree_head; current != Tree.Tree_end;
        current = current->next){
        insert(current->data);
    }
    //Tree_end = current;
    return *this;
}

template <class T>
int Tree<T>::getSize() const {
    return this->size;
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() const {
    return Iterator(this, Tree_head);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() const {
    return Iterator(this, Tree_end);
}

template <class T>
void Tree<T>::insert(const T &data, Iterator iterator) {
    if(iterator.current == Tree_end){
        insert(data);
        return;
    }
    Node *current = Tree_head;
    while (current != iterator.current && current != Tree_end){
        current = current->next;
    }
    if (current == Tree_end){
        throw ElementNotFound();
    }
    Node *newNode = new Node(data);
    newNode->next = current;
    if(current->previous != NULL){
        Node *previous = current->previous;
        previous->next = newNode;
        newNode->previous = previous;
    } else {
        newNode->next = Tree_head;
        Tree_head->previous = newNode;
        Tree_head = newNode;
        newNode->previous = NULL;
    }
    current->previous = newNode;
    size++;
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
