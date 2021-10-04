//
// Created by 浆布 on 03/10/2021.
//

#ifndef AI_UTIL_H
#define AI_UTIL_H
#include <list> // single linked list
#include <queue>
#include <iostream>
#include <stack>
#include "struct.h"
using namespace std;

bool exist(const list<status>& allStatus,const status& detect){
    for (auto pointer = allStatus.begin();pointer != allStatus.end();pointer++) {
        if (*pointer == detect) return true;
    }
    return false;
}

bool exist(const set<status>& allStatus,const status& detect){
    for (auto pointer = allStatus.begin();pointer != allStatus.end();pointer++) {
        if (*pointer == detect) return true;
    }
    return false;
}

bool exist(const multiset<status>& allStatus,const status& detect){
    for (auto pointer = allStatus.begin();pointer != allStatus.end();pointer++) {
        if (*pointer == detect) return true;
    }
    return false;
}

// status printer
void print(const status& pp){
    cout << "------------" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << pp.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

inline bool notOut(int x,int y){
    return (x >= 0 && x <= 2 && y >= 0 && y <= 2);
}

const status find(long hash,const list<status>& allStatus){
    for (auto pointer = allStatus.begin();pointer != allStatus.end();++pointer) {
        if (pointer->hash == hash) return *pointer;
    }
}

void printPath(long goalHash,const list<status>& allStatus){
    stack<status> path;
    path.push(find(goalHash,allStatus));
    while (path.top().hashP != -1){
        path.push(find(path.top().hashP,allStatus));
    }
    for (int i = 0 ;path.size() > 0; ++i) {
        print(path.top());
        path.pop();
    }
}



void genarate(const list<status>& open,list<status>& allStatus,list<status>& store){
    status now = *open.begin();
    list<status>* pass = new list<status>();
    int x;
    int y;
    int matrixNext[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrixNext[i][j] = now.matrix[i][j];
            if (now.matrix[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    if (notOut(x+1,y)){
        int temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x-1,y)){
        int temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x,y-1)){
        int temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x,y+1)){
        int temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    for (auto pointer = pass->begin(); pointer != pass->end();pointer++) {
        store.push_back(*pointer);
    }
    delete pass;
}

void genarate(const priority_queue<status>& open,list<status>& allStatus,priority_queue<status>& store){
    status now = open.top();
    list<status>* pass = new list<status>();
    int x;
    int y;
    int matrixNext[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrixNext[i][j] = now.matrix[i][j];
            if (now.matrix[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    if (notOut(x+1,y)){
        int temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x-1,y)){
        int temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x,y-1)){
        int temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x,y+1)){
        int temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    for (auto pointer = pass->begin(); pointer != pass->end();pointer++) {
        store.push(*pointer);
    }
    delete pass;
}

void genarate(const multiset<status>& open,list<status>& store){
    if(open.size() == 0){
        cout << "return"  << endl;
        return;
    };
    status now = *open.begin();
    list<status>* pass = new list<status>();
    int x;
    int y;
    int matrixNext[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrixNext[i][j] = now.matrix[i][j];
            if (now.matrix[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    if (notOut(x+1,y)){
        int temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    if (notOut(x-1,y)){
        int temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    if (notOut(x,y-1)){
        int temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    if (notOut(x,y+1)){
        int temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    for (auto pointer = pass->begin(); pointer != pass->end();pointer++) {
        store.push_front(*pointer);
    }
    delete pass;
}


void genarate(const multiset<status>& open,list<status>& store,const multiset<status>& before){
    if(open.size() == 0){
        cout << "return"  << endl;
        return;
    };
    status now = *open.begin();
    list<status>* pass = new list<status>();
    int x;
    int y;
    int matrixNext[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrixNext[i][j] = now.matrix[i][j];
            if (now.matrix[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    if (notOut(x+1,y)){
        int temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    if (notOut(x-1,y)){
        int temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    if (notOut(x,y-1)){
        int temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    if (notOut(x,y+1)){
        int temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        pass->push_front(toAdd);
    }
    for (auto pointer = pass->begin(); pointer != pass->end();pointer++) {
        if (!exist(before,*pointer))store.push_front(*pointer);
    }
    delete pass;
}

void genarate(priority_queue<status>& open,list<status>& allStatus,priority_queue<status>& store,list<status>& searched){
    int size = open.size();
    for (int i = 0; i < size; ++i) {
        if (exist(searched,open.top())){
            open.pop();
        }else break;
    }
    status now = open.top();
    searched.push_front(now);
    list<status>* pass = new list<status>();
    int x;
    int y;
    int matrixNext[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrixNext[i][j] = now.matrix[i][j];
            if (now.matrix[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    if (notOut(x+1,y)){
        int temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x+1][y];
        matrixNext[x+1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x-1,y)){
        int temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x-1][y];
        matrixNext[x-1][y] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x,y-1)){
        int temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y-1];
        matrixNext[x][y-1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    if (notOut(x,y+1)){
        int temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        status toAdd = status(now.legth+1,now.hash,matrixNext);
        temp = matrixNext[x][y+1];
        matrixNext[x][y+1] = matrixNext[x][y];
        matrixNext[x][y] = temp;
        if(!exist(allStatus,toAdd)){
            allStatus.push_front(toAdd);
            pass->push_front(toAdd);
        }
    }
    for (auto pointer = pass->begin(); pointer != pass->end();pointer++) {
        store.push(*pointer);
    }
    delete pass;
}

#endif //AI_UTIL_H
