#include "../utils/vector_util.h"
#include "../utils/invertable_binary_tree.h"

InvertableBinaryTree<char> invertTree(InvertableBinaryTree<char> tree) {
    tree.invert(tree.getRoot());
    return tree;
}
