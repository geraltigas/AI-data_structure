# AI-data_structure
store some data_structures and algorithm for my AI course

## data_structure

1. Linked_list(queue and stack).

2. MutiChild_Tree(based on the Linked_list)

   ``` c++
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
   
   ---
   output:
   D:\Projects\Cpp\AI\cmake-build-debug\AI.exe
   5
   6
   7
   2
   3
   4
   1
   
   Process finished with exit code 0
   ```

   

## utils

1. Universal Hash function for all data type

## algorithm

1. 

