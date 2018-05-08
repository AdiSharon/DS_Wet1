
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
        int node_height;
        Node *right_son; //the node's right son.
        Node *left_son; //the node's left son.
        Node *father; //the node's father. if node is the root, is null.


        Node(const T &data) :
                data(data),
                node_height(0),
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
   // Tree(const Tree &tree);

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

    int height(Tree<T>::Node *node);

    int getBalanceFactor(Tree<T>::Node *node);

    void updateHeight(Tree<T>::Node *node);

    template <typename Compare>
    Tree<T>::Node find(const T& data, Tree<T>::Node *root, Compare &compare);

    Tree<T>::Node rr_rotation(Tree<T>::Node *node);

    Tree<T>::Node rl_rotation(Tree<T>::Node *node);

    Tree<T>::Node ll_rotation(Tree<T>::Node *node);

    Tree<T>::Node lr_rotation(Tree<T>::Node *node);


    /*!
     * return the number of items in the linked Tree.
     * @return - the int number of items.
     */
    int getSize() const;

    Tree<T>::Node balance(Node *temp);

    /*!
     * function adds a new item to the Tree with the data value.
     * inserts at the Tree's end.
     * @param data - the new item's data.
     */
    template <typename Compare>
    Tree<T>::Node insert(const T &data, Node *root, const Compare &compare);

    template <typename Compare>
    void remove(const T& data, Compare &compare);

    template <typename Compare>
    void rotateRight(const Compare &compare);

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
        root (NULL){}



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
    this->size=tree.size;
    return *this;
}

template <class T>
int Tree<T>::getSize() const {
    return this->size;
}

template <class T>
int Tree<T>::getBalanceFactor(Tree<T>::Node *node){
    return (height(node->left_son) - height(node->right_son));
}

template <class T>
void Tree<T>::updateHeight(Tree<T>::Node *node){
    if(height(node->left_son) > height(node->right_son)){
        node->node_height = height(node->left_son) + 1;
    } else {
        node->node_height = height(node->right_son) + 1;
    }
}

template <class T>
template <typename Compare>
Tree<T>::Node Tree<T>::insert(const T &data, Node *root, const Compare &compare) {
    if (root == NULL){
        root= new Tree::Node(data);
        root->right_son=NULL;
        root->left_son=NULL;
        root->father=NULL;
        root->node_height=0;
        return root;

    } else if (compare(root->data, data) > 0) //compare returns true if left struct is bigger than right struct.
    {
        *root->left_son=Tree<T>::insert(data, root->left_son, compare);
    } else {
        *root->right_son=Tree<T>::insert(data, root->right_son, compare);
    }
    updateHeight(root);
    *root = Tree<T>::balance(root);
    return root;
}


template <class T>
Tree<T>::Node Tree<T>::rr_rotation(Tree<T>::Node *node);

template <class T>
Tree<T>::Node Tree<T>::rl_rotation(Tree<T>::Node *node);

template <class T>
Tree<T>::Node Tree<T>::ll_rotation(Tree<T>::Node *node);

template <class T>
Tree<T>::Node Tree<T>::lr_rotation(Tree<T>::Node *node);

template <typename Compare>
template <class T>
void Tree<T>::remove( const T& data, Compare &compare) {
    Tree<T>::Node temp = Tree<T>::find(data, this->root, compare);
    if(height(&temp) == 0){
        delete(temp);
        return;
    }
    bool left = false;
    if(temp.father->left_son == &temp){
        left= true;
    }
    if (temp.left_son == NULL ){
        if(left){
            temp.father->left_son = temp.right_son;
        } else {
            temp.father->right_son = temp.right_son;
        }
    } else if (temp.right_son == NULL){
        if(left){
            temp.father->left_son = temp.left_son;
        } else {
            temp.father->right_son = temp.left_son;
        }
    }

}

template <typename Compare>
template <class T>
Tree<T>::Node Tree<T>::find(const T& data, Tree<T>::Node *root, Compare &compare){
    if(compare(root->data, data ) == 0){
        return root;
    } else if (compare(root->data, data ) < 0 ){
        return find(data, root->right_son, compare);
    } else {
        return find(data, root->left_son, compare);
    }
    return NULL;
}

template <class T>
int Tree<T>::height(Tree<T>::Node *node){
    if (node != NULL){
        return node->node_height;
    }
    return -1;
}


#endif //HW2_TREE_H
