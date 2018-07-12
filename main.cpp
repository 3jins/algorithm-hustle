#include <iostream>
#include <vector>
//#include "linked_list.h"
#include "binary_tree.h"

using namespace std;

template <typename T>
void printVector(vector<T> v) {
    typename vector<T>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    BinaryTree<char> tree = BinaryTree<char>();
    tree.buildTree(tree.getRoot(), {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'});
    printVector(tree.preorderTraversal(tree.getRoot()));
    return 0;
}
