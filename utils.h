//
// Created by 浆布 on 25/09/2021.
//
#include <iostream>

using namespace std;

#ifndef AI_UTILS_H
#define AI_UTILS_H

template<typename T>
unsigned int BKDRhash(T *key, int scale);
int getMax(int* array,int scale);



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
        cout << i << endl;
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

#endif //AI_UTILS_H
