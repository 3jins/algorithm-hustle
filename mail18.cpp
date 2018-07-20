#include "vector_util.h"
#include "invertable_binary_tree.h"

InvertableBinaryTree<char> invertTree(InvertableBinaryTree<char> tree) {
    tree.invert(tree.getRoot());
    return tree;
}
