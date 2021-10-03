//
// Created by 浆布 on 02/10/2021.
//
#ifndef AI_HASHMAP_H
#define AI_HASHMAP_H

#include "LinkedList.h"
#include "utils.h"

template<typename Key,typename Val>
struct dataBlock{
    unsigned int hash;
    Key key;
    Val data;

    //TODO: FULLSILL
    dataBlock(unsigned int hash,Key key,Val data);
};

template<typename Key,typename Val>
class HashMap{
private:
    LinkedList<dataBlock<Key,Val>*>* valPool;
    unsigned int scale;
    //TODO: FULLFILL
    LinkedList<dataBlock<Key,Val>*>* getPool(Key key);
public:
    HashMap(unsigned int scale = 100);
    void clear();
    dataBlock<Key,Val>* find(Key key,bool(*func)(Val,Val));
    Val findData(Key key,bool(*func)(Val,Val));
    dataBlock<Key,Val>* add(Key key,Val data,bool(*func)(Val,Val));
};


//------------

template<typename Key, typename Val>
dataBlock<Key,Val>::dataBlock(unsigned int hash,Key key, Val data) {
    this->hash = hash;
    this->data = data;
    this->key = key;
}

template<typename Key, typename Val>
HashMap<Key, Val>::HashMap(unsigned int scale) {
    this->valPool = new LinkedList<dataBlock<Key,Val>*>[scale];
    this->scale = scale;
}

//-------------

template<typename Key, typename Val>
void HashMap<Key, Val>::clear() {
    for (int i = 0; i < this->scale; ++i) {
        valPool->pop();
    }
}

template<typename Key, typename Val>
dataBlock<Key,Val> *HashMap<Key, Val>::find(Key key,bool (*func)(Val,Val)) {
    auto pointer = getPool(key);
    if(pointer->getScale() == 0){
        return nullptr;
    }else{
        for (int i = 0; i < pointer->getScale(); ++i) {
            if(func(pointer->getData(i)->key,key)){
                return pointer->getData(i);
            }
        }
        return nullptr;
    }
}

template<typename Key, typename Val>
dataBlock<Key,Val> *HashMap<Key, Val>::add(Key key, Val data ,bool (*func)(Val,Val)) {
    auto pool = getPool(key);
    auto pointer = find(key,func);
    if(pointer){
        pointer->data = data;
        pointer->key = key;
    }else{
        auto temp = new dataBlock<Key,Val>(BKDRhash<Key>(&key,1),key,data);
        pool->push(temp);
        return temp;
    }
}

template<typename Key, typename Val>
LinkedList<dataBlock<Key,Val> *> *HashMap<Key, Val>::getPool(Key key) {
    unsigned int hash = BKDRhash<Key>(&key,1);
    unsigned int loca = hash%this->scale;
    auto pointer = valPool+loca;
    return pointer;
}

template<typename Key, typename Val>
Val HashMap<Key, Val>::findData(Key key, bool (*func)(Val, Val)) {
    auto pointer = find(key,func);
    if (pointer){
        return find(key,func)->data;
    } else{
        return Val();
    }

}

#endif //AI_HASHMAP_H
