#include <iostream>
#include "Tree.h"
using namespace std;
int main(){
    auto test = Tree<int>(1);
    auto root = test.getRoot();
    test.attach(root,2);
    test.attach(root,3);
    test.attach(root,4);
    auto children1 = test.getChildren(root);
    test.attach((*children1)[0],5);
    test.attach((*children1)[0],6);
    test.attach((*children1)[0],7);
    auto list = test.PosTraverse();
    for (int i = 0; i < list->getScale(); ++i) {
        cout << (*list)[i]->data << endl;
    }
}
