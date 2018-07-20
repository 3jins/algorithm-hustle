#include <iostream>
#include "invertable_binary_tree.h"
#include "mail18.cpp"

using namespace std;

int main() {
    InvertableBinaryTree<char> tree = InvertableBinaryTree<char>();
    tree.buildTree(tree.getRoot(), {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'});
    printVector(tree.preorderTraversal(tree.getRoot()), " ");
    tree = invertTree(tree);
    printVector(tree.preorderTraversal(tree.getRoot()), " ");
    return 0;
}
