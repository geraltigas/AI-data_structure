//
// Created by 浆布 on 26/09/2021.
//

#include "LinkedList.h"
#include <iostream>

#ifndef AI_TREE_H
#define AI_TREE_H

template<typename T>
struct TreeNode{
    int height;
    int depth;
    TreeNode<T>* parent;
    T data;
    LinkedList<TreeNode<T>*>* Children;
    TreeNode();
    TreeNode(int height,TreeNode<T>* parent,T data,LinkedList<TreeNode<T>*>* Chilren);
    ~TreeNode();
};


template<typename T>
class Tree{
private:
    TreeNode<T>* root;
public:
    Tree();
    Tree(TreeNode<T>*);
    ~Tree();
    ~Tree(TreeNode<T>*);
    TreeNode<T>* attach(TreeNode<T>* parent,T data); //TODO
    TreeNode<T>* remove(TreeNode<T>* node);  //TODO
    int updateHeight(TreeNode<T>* node);  //TODO
    int updateWidth(TreeNode<T>* node);  //TODO
    TreeNode<T>* getParent(TreeNode<T>* node);  //TODO
    TreeNode<T>* getChildren(TreeNode<T>* node);  //TODO
};


//---------

template<typename T>
TreeNode<T>::TreeNode() {
    this->height = -1;
    this->depth = -1;
    this->parent = nullptr;
    this->data = T();
    this->Children = nullptr;
}

template<typename T>
TreeNode<T>::TreeNode(int height, TreeNode<T> *parent, T data, LinkedList<TreeNode<T> *> *Chilren) {
    this->height = height;
    this->parent = parent;
    this->data = data;
    this->depth = depth;
    this->Children = Chilren;
}

template<typename T>
TreeNode<T>::~TreeNode() {
    if(this->Children == nullptr) {
        return;
    }else{
        for (int i = 0; i < this->Children->getScale(); ++i) {
            this->Children->getNode(i)->data->~TreeNode();
        }
    }
}

//-------

template<typename T>
Tree<T>::Tree() {
    this->root = TreeNode<T>();
}

template<typename T>
Tree<T>::Tree(TreeNode<T> * root) {
    this->root = root;
}

template<typename T>
Tree<T>::~Tree() {
    this->root->~TreeNode();
}

template<typename T>
Tree<T>::~Tree(TreeNode<T> * reRoot) {
    reRoot->~TreeNode();
}

template<typename T>
TreeNode<T> *Tree<T>::attach(TreeNode<T> *parent, T data) {
    TreeNode<T>* pointer =
    return nullptr;
}

template<typename T>
TreeNode<T> *Tree<T>::remove(TreeNode<T> *node) {
    return nullptr;
}

template<typename T>
int Tree<T>::updateHeight(TreeNode<T> *node) {
    return 0;
}

template<typename T>
int Tree<T>::updateWidth(TreeNode<T> *node) {
    return 0;
}

template<typename T>
TreeNode<T> *Tree<T>::getParent(TreeNode<T> *node) {
    return nullptr;
}

template<typename T>
TreeNode<T> *Tree<T>::getChildren(TreeNode<T> *node) {
    return nullptr;
}

#endif //AI_TREE_H
