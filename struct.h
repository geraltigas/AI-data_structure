//
// Created by 浆布 on 03/10/2021.
//

#ifndef AI_STRUCT_H
#define AI_STRUCT_H


// hash function
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

struct status{
    unsigned long hashP;
    int matrix[3][3];
    static bool isBeFS;
    unsigned long hash;
    unsigned int legth;
    status(unsigned int legth,long hashP,int matrixs[3][3]);
    bool operator==(const status& tar) const;
    bool operator<(const status& left) const;
};

bool status::isBeFS = true;

status::status(unsigned int legth,long hashP,int matrixs[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->matrix[i][j] = matrixs[i][j];
        }
    }
    this->hashP = hashP;
    this->hash = BKDRhash<int>(&(this->matrix[0][0]),9);
    this->isBeFS = false;
    this->legth = legth;
}

bool status::operator==(const status &tar) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->matrix[i][j]!=tar.matrix[i][j]) return false;
        }
    }
    return true;
}

int aStar(const status& sta){
    static int matrisO[3][3] = {
            {1,2,3},
            {8,0,4},
            {7,6,5}
    };
    int goal = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrisO[i][j] == sta.matrix[i][j]) goal++;
        }
    }
    return (goal + sta.legth);
}

int getBF(const status& sta){
    static int matrisO[3][3] = {
            {1,2,3},
            {8,0,4},
            {7,6,5}
    };
    int goal = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrisO[i][j] == sta.matrix[i][j]) goal++;
        }
    }
    return goal;
}

bool status::operator<(const status &left) const {
    if (isBeFS){
        return getBF(*this) < getBF(left);
    }else{
        return aStar(*this) < aStar(left);
    }
}

#endif //AI_STRUCT_H
