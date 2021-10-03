//
// Created by 浆布 on 25/09/2021.
//
#include <iostream>
#include <ctime>

using namespace std;

#ifndef AI_UTILS_H
#define AI_UTILS_H

template<typename T>
unsigned int BKDRhash(T *key, int scale);
int getMax(int* array,int scale);
int getRand(int a,int b);


//--------
template<typename T>
unsigned int BKDRhash(T *key, int scale) {
    unsigned int seed = 131;
    unsigned int hash = 0;
    char *point = (char *) key;
    int i = 0;
    while (i < scale * sizeof(T)) {
        hash = hash * seed + (*point++);
        i++;
    }
    return hash;
};


int getMax(int *array, int scale) {
    int maxRank = 0;
    for (int i = 0; i < scale; ++i) {
        if (array[i] > array[maxRank]){
            maxRank = i;
        }
    }
    return maxRank;
}

int getRand(int a,int b){
    static unsigned int recorde = unsigned(time(0));
    static unsigned int del = 0;
    unsigned int randSeed;
    randSeed = recorde+del;
    srand(randSeed);
    int delta = rand()%(b-a+1);
    del = rand();
    return a+delta;
}

#endif //AI_UTILS_H
