#include <iostream>
#include "LinkedList.h"
using namespace std;


int main(){
    LinkedList<int> array = LinkedList<int>();
    array.push(1);
    array.push(2);
    array.pop();
    array.pop();
    array.push(13);
    for (int i = 0; i < 2; ++i) {
        cout << array.getData(i) << endl;
    }
}
