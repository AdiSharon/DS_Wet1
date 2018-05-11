
#ifndef HW2_TREE_H
#define HW2_TREE_H

#include <iostream>
#include <algorithm>
#include "Execptions.h"

using namespace std;
using namespace DS::Tree;

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

        ~Node() {
            //delete (this->data);
            //delete(this)
        }

    public:

        //default assignment operand.
        Node &operator=(const Node &node){
            this->data=node.data;
            this->father=node.father;
            this->left_son=node.left_son;
            this->right_son=node.right_son;
            this->node_height=node.node_height;
            return *this;
        }

        void Print() const{
            std::cout << data << std::endl;
        }

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
    ~Tree() {};

    void deleteNode(Node *node){
        if( node ){
            deleteNode(node->right_son);
            deleteNode(node->left_son);
            delete (node);
        }
    }

    void deleteTree() {
        if(this->root){
            deleteNode(this->root);
            this->size=0;
            this->root=NULL;
        }
    }

    /*!
     * an assignment operator
     * @param Tree - the Tree to be assigned.
     * @return ref to a new Tree that contains the assigned values.
     */
    Tree &operator=(const Tree &tree);

    int height(Tree<T>::Node *node);

    Node* getRoot(Tree tree){
        return this->root;
    }

    int getBalanceFactor(Tree<T>::Node *node);

    void updateHeight(Node *node);

    template <typename Compare>
    Node* find(const T& data, Node *root, Compare &compare){
        if(!root){
            return NULL;
        }
        if(compare(root->data, data ) == 0){
            return root;
        } else if (compare(root->data, data ) < 0 ){
            return find(data, root->right_son, compare);
        }
        return find(data, root->left_son, compare);
    }

    Node rr_rotation(Node *node){
        rotateLeft(node);
        return *node;
    }

    Node rl_rotation(Node *node){
        rotateRight(node->right_son);
        rotateLeft(node);
        return *node;
    }

    Node ll_rotation(Node *node){
        rotateRight(node);
        return *node;
    }

    Node lr_rotation(Node *node) {
        rotateLeft(node->left_son);
        rotateRight(node);
        return *node;
    }

    /*!
     * return the number of items in the linked Tree.
     * @return - the int number of items.
     */
    int getSize() const;

    void balance(Node *root);

    /*!
     * function adds a new item to the Tree with the data value.
     * inserts at the Tree's end.
     * @param data - the new item's data.
     */
    template <typename Compare>
    void insert(const T &data, Node *root, Compare &compare){
        if (this->root == NULL){ //if tree is empty
            this->root= new Node(data);
            this->root->right_son=NULL;
            this->root->left_son=NULL;
            this->root->father=NULL;
            this->root->node_height=0;
            root=this->root;
            this->size++;
            //return root;

        } else if (compare(root->data, data) == 0){
            return;
        }else if (compare(root->data, data) > 0)
            {
                if(root->left_son){
                    insert(data, root->left_son, compare);
                } else {
                    //Node *newnode = new Node(data);
                    root->left_son = new Node(data);
                    root->left_son->father = root;
                    this->size++;
                    if (root->node_height == 0){
                        Node *Iterator = root;
                        while (Iterator->father != NULL){
                            updateHeight(Iterator);
                            Iterator=Iterator->father;
                        }
                        updateHeight(this->root);
                    }
                }
            }  else {
            if(root->right_son){
                    insert(data, root->right_son, compare);
                } else {
                    //Node *newnode = new Node(data);
                    root->right_son = new Node(data);
                    root->right_son->father = root;
                    this->size++;
                    if (root->node_height == 0){
                        Node *Iterator = root;
                        while (Iterator->father != NULL){
                            updateHeight(Iterator);
                            Iterator=Iterator->father;
                        }
                        updateHeight(this->root);
                    }
                }
            }
        //this->size++;
        balance(root);
    }

    template <typename Compare>
    void remove(const T& data, Compare &compare){
        Node *node = find(data, this->root, compare);
        if (node == NULL){
            return;
        }
        //node has NO sons:
        if(height(node) == 0){
            this->size--;
            if(node->father->left_son == node){
                node->father->left_son = NULL;
            } else {
                node->father->right_son = NULL;
            }
            updateHeight(node->father);
            delete(node);
            return;
        }
        //check if node is the left son of his father
        bool left = false;
        bool isRoot = false;
        if (!node->father){
            isRoot = true;
        }
        if(!isRoot){
            if(node->father->left_son == node){
                left = true;
            }
        }
        //node has ONE son:
        if (node->left_son == NULL || node->right_son == NULL){
            if (node->left_son == NULL ){
                if(left){
                    node->father->left_son = node->right_son;
                    node->right_son->father = node->father;
                } else if (!isRoot){
                    node->father->right_son = node->right_son;
                    node->right_son->father = node->father;
                } else {
                    this->root = node->right_son;
                }

            } else if (node->right_son == NULL){
                if(left){
                    node->father->left_son = node->left_son;
                    node->left_son->father = node->father;
                } else if (!isRoot){
                    node->father->right_son = node->left_son;
                    node->left_son->father = node->father;
                } else {
                    this->root = node->right_son;
                }

            }
            this->size--;
            if (!isRoot){
                updateHeight(node->father);
            }
            delete(node);
        }
            //node has TWO sons:
        else if (node->left_son && node->right_son){
            Node *temp = findClosestMin(node);
            node->data = temp->data;
            temp->data = data;
            if (!temp->father->left_son ||temp->father->left_son == temp ){
                temp->father->left_son = NULL;
                temp->father->left_son = temp->right_son;
            } else if (temp->father->right_son == temp){
                temp->father->right_son = temp->right_son;
            }
            if(temp->right_son){
                temp->right_son->father = temp->father;
            }
            this->size--;
            if(!isRoot){
                updateHeight(temp->father);
            }
            delete(temp);
        }
    }

    void rotateRight(Node *root);

    void rotateLeft(Node *root);

    Node *findClosestMin(Node *node){
        Node *min = node->right_son;
        while (min->left_son){
            min = min->left_son;
        }
        return min;
    }

    bool operator==(const Tree &tree) const{
        return this->size == tree.size;
    }

    bool operator!=(const Tree &tree) const{
        return this->size != tree.size;
    }

    bool operator>(const Tree &tree) const{
        return this->size > tree.size;
    }

    bool operator<(const Tree &tree) const{
        return this->size < tree.size;
    }

    void PreOrder (Node *root) const;

    void InOrder (Node *root) const;

    void PostOrder (Node *root) const;




};

template <class T>
Tree<T>::Tree() :
        size(HEAD_INDEX),
        root (NULL){} ;



/*template <class T>
Tree<T>::~Tree() {
    Node *node = this->root;
    if (node != NULL){
        delete (node);
    }
    //delete(this);
}*/

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

/*template <typename Compare>
template <typename T>
Tree<T>::Node* Tree<T>::insert(const T &data, Node *root, const Compare &compare) {
    if (root == NULL){ //if tree is empty
        root= new Tree::Node(data);
        root->right_son=NULL;
        root->left_son=NULL;
        root->father=NULL;
        root->node_height=0;
        return root;

    } else if (compare(root->data, data) < 0)
    {
        if(root->left_son){
            *root->left_son=Tree<T>::insert(data, root->left_son, compare);
        } else {
            Tree<T>::Node *newnode = new Tree::Node(data);
            root->left_son = newnode;
            newnode->father = root;
        }
    } else {
        if(root->right_son){
            *root->right_son=Tree<T>::insert(data, root->right_son, compare);
        } else {
            Tree<T>::Node *newnode = new Tree::Node(data);
            root->right_son = newnode;
            newnode->father = root;
        }
    }
    if (root->node_height == 0){
        Tree<T>::Node *Iterator = root;
        while (Iterator->father != NULL){
            updateHeight(Iterator);
        }
        updateHeight(this->root);
    }
    this->size++;
    Tree<T>::balance(root);
    return root;
}*/

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
void Tree<T>::rotateLeft(Tree<T>::Node *root){
    Tree<T>::Node *newroot = root->right_son;
    root->right_son = NULL;
    root->right_son=newroot->left_son;
    newroot->left_son = root;
    if (root->father == NULL){
        this->root = newroot;
        newroot->father = NULL;
    } else {
        if (root->father->left_son == root){
            root->father->left_son = newroot;
        } else {
            root->father->right_son = newroot;
        }
        newroot->father = root->father;
    }
    root->father = newroot;
    updateHeight(root);
    updateHeight(newroot);
    //updateHeight(newroot->father);
}

template <class T>
void Tree<T>::rotateRight(Tree<T>::Node *root){
    Tree<T>::Node *newroot = root->left_son;
    root->left_son = NULL;
    root->left_son = NULL;
    root->left_son=newroot->right_son;
    newroot->right_son = root;
    if (root->father == NULL){
        this->root = newroot;
        newroot->father = NULL;
    } else {
        if (root->father->left_son == root){
            root->father->left_son = newroot;
        } else {
            root->father->right_son = newroot;
        }
        newroot->father = root->father;
    }
    root->father = newroot;
    updateHeight(root);
    updateHeight(newroot);
}

/*template <class T>
Tree<T>::Node Tree<T>::rr_rotation(Tree<T>::Node *node){
    Tree<T>::rotateLeft(node);
    return node;
}

template <class T>
Tree<T>::Node Tree<T>::rl_rotation(Tree<T>::Node *node){
    Tree<T>::rotateRight(node->right_son);
    Tree<T>::rotateLeft(node);
    return node;
}

template <class T>
Tree<T>::Node Tree<T>::ll_rotation(Tree<T>::Node *node){
    Tree<T>::rotateRight(node);
    return node;
}

template <class T>
Tree<T>::Node Tree<T>::lr_rotation(Tree<T>::Node *node){
    Tree<T>::rotateLeft(node->left_son);
    Tree<T>::rotateRight(node);
    return node;
}*/

/*template <class T>
Tree<T>::Node* Tree<T>::findClosestMin(Tree<T>::Node *node){
    Tree<T>::Node *min = node->right_son;
    while (min->left_son){
        min = min->left_son;
    }
    return min;
}*/

/*template <typename Compare>
template <class T>
void Tree<T>::remove( const T& data, Compare &compare) {
    Tree<T>::Node *node = Tree<T>::find(data, this->root, compare);
    if (node == NULL){
        return;
    }
    //node has NO sons:
    if(height(node) == 0){
        delete(*node);
        this->size--;
        return;
    }
    //check if node is the left son of his father
    bool left = false;
    if(node->father->left_son == node){
        left = true;
    }
    //node has ONE son:
    if (node->left_son == NULL || node->right_son == NULL){
        if (node->left_son == NULL ){
            if(left){
                node->father->left_son = node->right_son;
            } else {
                node->father->right_son = node->right_son;
            }
        } else if (node->right_son == NULL){
            if(left){
                node->father->left_son = node->left_son;
            } else {
                node->father->right_son = node->left_son;
            }
        }
        updateHeight(node->father);
        delete(*node);
        this->size--;
    }
    //node has TWO sons:
    else if (node->left_son && node->right_son){
        Tree<T>::Node *temp = Tree<T>::findClosestMin(node);
        node->data = temp->data;
        temp->data = data;
        Tree<T>::remove(data, compare);
    }
}*/

/*template <typename Compare>
template <class T>
Tree<T>::Node* Tree<T>::find(const T& data, Tree<T>::Node *root, Compare &compare){
    if(compare(root->data, data ) == 0){
        return root;
    } else if (compare(root->data, data ) < 0 ){
        return find(data, root->right_son, compare);
    } else {
        return find(data, root->left_son, compare);
    }
    return NULL;
}*/

template <class T>
int Tree<T>::height(Tree<T>::Node *node){
    if (node != NULL){
        return node->node_height;
    }
    return -1;
}

template <class T>
void Tree<T>::balance(Tree<T>::Node *root){
    int BF = getBalanceFactor(root);
    if (BF >= -1 && BF <= 1)
        return;
    if (BF == 2){
        if (getBalanceFactor(root->left_son) > 0){
            ll_rotation(root);
        } else if (getBalanceFactor(root->left_son) == -1){
            lr_rotation(root);
        }
        Node *Iterator = root;
        while (Iterator->father != NULL){
            updateHeight(Iterator);
            Iterator=Iterator->father;
        }
        updateHeight(this->root);
        return;
    } else if (BF == -2){
        if (getBalanceFactor(root->right_son) <= 0){
            rr_rotation(root);

        } else if (getBalanceFactor(root->right_son) == 1){
            rl_rotation(root);
        }
        Node *Iterator = root;
        while (Iterator->father != NULL){
            updateHeight(Iterator);
            Iterator=Iterator->father;
        }
        updateHeight(this->root);
        return;
    }
    throw TreeBFProblem();
}

template<class T>
void Tree<T>::PreOrder (Tree<T>::Node *root) const{
    if( root ){
        root->Print();
        Tree<T>::PreOrder(root->left_son);
        Tree<T>::PreOrder(root->right_son);
    }
}

template <class T>
void Tree<T>::InOrder (Tree<T>::Node *root) const{
    if (root){
        Tree<T>::InOrder(root->left_son);
        root->Print();
        Tree<T>::InOrder(root->right_son);
    }
}

template <class T>
void Tree<T>::PostOrder (Tree<T>::Node *root) const{
    if(root){
        Tree<T>::PostOrder(root->left_son);
        Tree<T>::PostOrder(root->right_son);
        root->Print();
    }
}


#endif //HW2_TREE_H
