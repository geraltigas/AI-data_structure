// headfile
#include <list> // single linked list
#include <iostream>
#include <stack>
#include <set>
#include "struct.h"
#include "util.h"
using std::stack;
using std::cout;
using std::endl;
using std::list;

int originStatus[3][3] = {
        {2,8,3},
        {1,6,4},
        {7,0,5}
};

int goalStatus[3][3] = {
        {1,2,3},
        {8,0,4},
        {7,6,5}
};



// different searching method;

// depth first searching
void dfs(){
    cout << "depth first search" << endl;
    status origin = status(0,-1,originStatus);
    status goal = status(0,-1,goalStatus);
    list<status> allStatus;
    list<status> open;
    queue<status> closed;
    long goalHash = -1;

    // init
    allStatus.push_back(origin);
    open.push_back(origin);
    list<status> nextStstuses = list<status>();
    //genarate next status
    while (goalHash == -1){
        genarate(open,allStatus,nextStstuses);
        open.pop_front();
        for (auto pointer = nextStstuses.begin(); pointer != nextStstuses.end() ; ++pointer) {
            if (*pointer == goal){
                goalHash = pointer->hash;
                break;
            } else{
                if(pointer->legth <= 5){
                    open.push_front(*pointer);
                }
            }
        }
        nextStstuses.clear();
    }
    printPath(goalHash,allStatus);
}

// breadth first searching
void bfs(){
    cout << "breadth first search" << endl;
    status origin = status(0,-1,originStatus);
    status goal = status(0,-1,goalStatus);
    list<status> allStatus;
    list<status> open;
    queue<status> closed;
    long goalHash = -1;

    // init
    allStatus.push_back(origin);
    open.push_back(origin);
    list<status> temList;
    while (goalHash == -1){
        int size = open.size();
        for(auto i = 0; i < size;i++){
            genarate(open,allStatus,temList);
            open.pop_front();
        }
        for (auto poi = temList.begin(); poi != temList.end(); poi++) {
            open.push_back(*poi);
        }
        for (auto pointer = open.begin(); pointer != open.end() ; ++pointer) {
            if (*pointer == goal){
                goalHash = pointer->hash;
                break;
            } else{
            }
        }
        temList.clear();
    }
    printPath(goalHash,allStatus);
}

// climb


void clime(){
    cout << "hill climing search" << endl;
    status origin = status(0,-1,originStatus);
    status goal = status(0,-1,goalStatus);

    long goalhash = -1;
    multiset<status> open;
    multiset<status> closed;
    open.insert(origin);
    list<status> temp;

    status::isBeFS = true;

    while(goalhash == -1){
        genarate(open,temp,closed);
        closed.insert(*open.begin());
        open.clear();
        for (auto i = temp.begin(); i != temp.end() ; ++i) {
            if (!exist(closed,*i) ){
                if( *i == goal) {
                    goalhash = i->hash;
                    break;
                }else{
                    open.insert(*i);
                    closed.insert(*i);
                }
            }
        }
        temp.clear();
        if (goalhash != -1) break;
    }
//
//    while (goalhash == -1){
//        genarate(open,temp);
//        open.clear();
//        for (auto i = temp.begin(); i != temp.end() ; ++i) {
//            if(!exist(allStatus,*i)){
//                if (*i == goal){
//                    goalhash = i->hash;
//                }else{
//                    open.insert(*i);
//                    allStatus.insert(*i);
//                }
//            }
//        }
//        temp.clear();
//    }

    list<status> listP;
    for (auto i = closed.begin(); i != closed.end() ; ++i) {
        listP.push_back(*i);
    }

    stack<status> path;

    path.push(goal);

    while (goalhash != -1){
        status ok = find(goalhash,listP);
        path.push(ok);
        goalhash = ok.hashP;
    }


    while (!path.empty()){
        status ok = path.top();
        print(ok);
        path.pop();
    }

}


// best-first searching
void bestFirstSearching(){
    cout << "best first search" << endl;
    status origin = status(0,-1,originStatus);
    status goal = status(0,-1,goalStatus);

    multiset<status> open;
    open.insert(origin);

    list<status> temp;

    multiset<status> closed;

    multiset<status> allStatus;
    allStatus.insert(origin);

    long goalhash = -1;

    while (goalhash == -1){
        genarate(open,temp);
        status temps = *open.begin();
        closed.insert(temps);
        open.erase(open.begin());
        for (auto i = temp.begin(); i != temp.end() ; ++i) {
            if(!exist(allStatus,*i)){
                if (*i == goal){
                    goalhash = i->hash;
                }else{
                    open.insert(*i);
                    allStatus.insert(*i);
                }
            }
        }
    }

    list<status> listP;
    for (auto i = allStatus.begin(); i != allStatus.end() ; ++i) {
        listP.push_back(*i);
    }

    stack<status> path;

    path.push(goal);

    while (goalhash != -1){
        status ok = find(goalhash,listP);
        path.push(ok);
        goalhash = ok.hashP;
    }


    while (!path.empty()){
        status ok = path.top();
        print(ok);
        path.pop();
    }

}

// a_star searching
void aStarSearching(){
    cout << "a star sreaching" << endl;
    status origin = status(0,-1,originStatus);
    status goal = status(0,-1,goalStatus);

    status::isBeFS = false;

    multiset<status> open;
    open.insert(origin);

    list<status> temp;

    multiset<status> closed;

    multiset<status> allStatus;
    allStatus.insert(origin);

    long goalhash = -1;

    while (goalhash == -1){
        genarate(open,temp);
        status temps = *open.begin();
        closed.insert(temps);
        open.erase(open.begin());
        for (auto i = temp.begin(); i != temp.end() ; ++i) {
            if(!exist(allStatus,*i)){
                if (*i == goal){
                    goalhash = i->hash;
                }else{
                    open.insert(*i);
                    allStatus.insert(*i);
                }
            }
        }
    }

    list<status> listP;
    for (auto i = allStatus.begin(); i != allStatus.end() ; ++i) {
        listP.push_back(*i);
    }

    stack<status> path;

    path.push(goal);

    while (goalhash != -1){
        status ok = find(goalhash,listP);
        path.push(ok);
        goalhash = ok.hashP;
    }


    while (!path.empty()){
        status ok = path.top();
        print(ok);
        path.pop();
    }

}


int main(){
    dfs();
    bfs();

    status::isBeFS = true;
//    clime();
    bestFirstSearching();
    aStarSearching();
}