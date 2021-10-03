#include <iostream>
#include "Tree.h"
#include "Hashmap.h"
#include "utils.h"
#include "Hashmap.h"
using namespace std;
struct order {
    int yuanyin;
    int fuyin;
};

bool result[1000][500] = {false};

order matris[10][5] = {{0,0}};

void setResult(int yuanyin,int fuyin){
    result[yuanyin-1][fuyin-1] = true;
}

bool getResult(int yuanyin,int fuyin){
    return result[yuanyin-1][fuyin-1];
}


int main(){
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 5; ++j) {
            matris[i-1][j-1].yuanyin = getRand(1,5);
            matris[i-1][j-1].fuyin = getRand(1,10);
//            cout << "(" << matris[i-1][j-1].yuanyin << "," << matris[i-1][j-1].fuyin << ") ";
            while (getResult(matris[i-1][j-1].yuanyin,matris[i-1][j-1].fuyin)){
//                cout << "有重复" << endl;
                matris[i-1][j-1].yuanyin = getRand(1,5);
                matris[i-1][j-1].fuyin = getRand(1,10);
//                cout << "(" << matris[i-1][j-1].yuanyin << "," << matris[i-1][j-1].fuyin << ") ";
            }
            setResult(matris[i-1][j-1].yuanyin,matris[i-1][j-1].fuyin);
        }
        cout << endl << "第" << i << "天" << endl;
        for (int x = 1; x <= 5; ++x) {
            cout << "(" << matris[i - 1][x - 1].yuanyin << "," << matris[i - 1][x - 1].fuyin << ") ";
        }
    }
}

//bool* array =new bool[50];
//
//order* getOrder(order * matix,int day, int sequence){
//    return matix +5*(day-1) + (sequence -1);
//}
//
//bool isExist(int yuanyin,int fuyin){
//    return *(array+10*(yuanyin-1)+(fuyin-1));
//}
//
//void setExist(int day,int sequence){
//    *(array+10*(day-1)+(sequence-1)) = true;
//}
//
//int main(){
//    for (int i = 0; i < 50; ++i) {
//        array[i] = false;
//    }
//    order *matix = new order[10*5];
//    for (int i = 1; i <= 10; ++i) {
//        for (int j = 1; j <= 5; ++j) {
//            order* pointer = getOrder(matix,i,j);
//            pointer->fuyin = getRand(1,10);
//            pointer->yuanyin = getRand(1,5);
//            while (isExist(pointer->yuanyin,pointer->fuyin)) {
//                pointer->fuyin = getRand(1,10);
//                pointer->yuanyin = getRand(1,5);
//            }
//            setExist(pointer->yuanyin,pointer->fuyin);
//        }
//        cout << "第" << i << "天"<< endl;
//        for (int x = 1; x <= 5; ++x) {
//            cout << "(" <<getOrder(matix,i,x)->yuanyin << "," << getOrder(matix,i,x)->fuyin << ") ";
//        }
//        cout << endl;
//    }
//}


