//
// Created by 浆布 on 26/09/2021.
//

#include "LinkedList.h"
#include "utils.h"
#include <iostream>

#ifndef AI_TREE_H
#define AI_TREE_H

template<typename T>
struct TreeNode {
    int height;
    int depth;
    TreeNode<T> *parent;
    T data;
    LinkedList<TreeNode<T> *> *Children;

    TreeNode();
    TreeNode(int height,int depth,TreeNode<T> *parent, T data, LinkedList<TreeNode<T> *> *Chilren);

    ~TreeNode();

    int getChildrenScale();
};


template<typename T>
class Tree {
private:
    TreeNode<T> *root;
    LinkedList<TreeNode<T> *> *PosTraverse(LinkedList<TreeNode<T> *> *,TreeNode<T>*);  //TODO
public:
    Tree();
    Tree(T data);
    Tree(TreeNode<T> *);

    ~Tree();
    TreeNode<T>* getRoot();
    TreeNode<T> *attach(TreeNode<T> *parent, T data);
    TreeNode<T> *remove(TreeNode<T> *node);
    int updateHeight(TreeNode<T> *node);
    int updateDepth(TreeNode<T> *node);
    TreeNode<T> *getParent(TreeNode<T> *node);
    LinkedList<TreeNode<T> *> *getChildren(TreeNode<T> *node);
    LinkedList<TreeNode<T> *> *PosTraverse();  //TODO
};


//---------

template<typename T>
TreeNode<T>::TreeNode() {
    this->height = -1;
    this->depth = -1;
    this->parent = nullptr;
    this->data = T();
    this->Children = new LinkedList<TreeNode<T>*>();
}

template<typename T>
TreeNode<T>::TreeNode(int height,int depth,TreeNode<T> *parent, T data, LinkedList<TreeNode<T> *> *Chilren) {
    this->height = height;
    this->depth = depth;
    this->parent = parent;
    this->data = data;
    this->Children = Chilren;
}

template<typename T>
TreeNode<T>::~TreeNode() {
    this->Children->~LinkedList<TreeNode<T>*>();
}

template<typename T>
int TreeNode<T>::getChildrenScale() {
    return Children->getScale();
}

//-------

template<typename T>
Tree<T>::Tree(T data) {
    this->root = new TreeNode<T>(-1,-1 ,nullptr,data, nullptr);
}

template<typename T>
Tree<T>::Tree() {
    this->root = new TreeNode<T>();
}

template<typename T>
Tree<T>::Tree(TreeNode<T> *root) {
    this->root = root;
}

template<typename T>
Tree<T>::~Tree() {
    LinkedList<TreeNode<T>* >* list = PosTraverse();
    for (int i = 0; i < list->getScale(); ++i) {
        (*list)[i]->~TreeNode();
    }
}


template<typename T>
TreeNode<T> *Tree<T>::attach(TreeNode<T> *parent, T data) {
    auto pointer = new TreeNode<T>(-1,-1,parent,data,new LinkedList<TreeNode<T>*>());
    if (parent->Children == nullptr) {
        parent->Children = new LinkedList<TreeNode<T> *>();
    }
    parent->Children->push(pointer);
    return pointer;
}

template<typename T>
TreeNode<T> *Tree<T>::remove(TreeNode<T> *node) {
    auto parent = node->parent;
    int i = 0;
    while (parent->Children->getNode(i) != node) {
        i++;
    }
    parent->Children->popByRank(i);
    return node;
}

template<typename T>
int Tree<T>::updateHeight(TreeNode<T> *node) {
    if (node->Children == nullptr || node->Children->getScale() == 0) {
        node->height = 0;
        return 0;
    }else{
        int* heightArray = new int[node->getChildrenScale()];
        for (int i = 0; i < node->getChildrenScale(); ++i) {
            heightArray[i] = this->updateHeight(heightArray[i] = node->Children->getNode(i)->data);
        }
        node->height = getMax(heightArray,node->getChildrenScale());
        delete heightArray;
        return node->height;
    }
}

template<typename T>
int Tree<T>::updateDepth(TreeNode<T> *node) {
    TreeNode<T>* formmer = nullptr;
    int i = 0;
    while (formmer->parent != nullptr){
        formmer = formmer->parent;
        ++i;
    }
    node->depth = i;
    return i;
}

template<typename T>
TreeNode<T> *Tree<T>::getParent(TreeNode<T> *node) {
    return node->parent;
}

template<typename T>
LinkedList<TreeNode<T> *> *Tree<T>::getChildren(TreeNode<T> *node) {
    if (node->Children == nullptr) {
        node->Children == new LinkedList<TreeNode<T>*>();
    }
    return node->Children;
}

template<typename T>
TreeNode<T> *Tree<T>::getRoot() {
    return this->root;
}

template<typename T>
LinkedList<TreeNode<T> *> *Tree<T>::PosTraverse() {
    auto pointer = new LinkedList<TreeNode<T> *>();
    PosTraverse(pointer,this->root);
    return pointer;
}

template<typename T>
LinkedList<TreeNode<T> *> *Tree<T>::PosTraverse(LinkedList<TreeNode<T> *> * list,TreeNode<T>* reRoot) {
    if (reRoot->Children->getScale() == 0){
    }else{
        auto lists = reRoot->Children;
        for (int i = 0; i < lists->getScale(); ++i) {
            PosTraverse(list,(*lists)[i]);
        }
    }
    list->push(reRoot);
    return list;
}


#endif //AI_TREE_H
