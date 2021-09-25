//
// Created by 浆布 on 25/09/2021.
//
#include <iostream>

using namespace std;

#ifndef AI_UTILS_H
#define AI_UTILS_H

template<typename T>
unsigned int BKDRhash(T *key, int scale);


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

#endif //AI_UTILS_H
