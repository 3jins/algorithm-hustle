#ifndef ALGORITHM_HUSTLE_INVERTABLE_BINARY_TREE_H
#define ALGORITHM_HUSTLE_INVERTABLE_BINARY_TREE_H

#include "binary_tree.h"

template<typename T>
class InvertableBinaryTree : public BinaryTree<T> {
    friend class BinaryTree<T>;
    TreeNode<T> *root;
public:
    InvertableBinaryTree(T rootData = 0);
    void swap(TreeNode<T> *parent);
    void invert(TreeNode<T> *root);
};

template <typename T>
InvertableBinaryTree<T>::InvertableBinaryTree(T rootData) {
    root = new TreeNode<T>(rootData);
}

template<typename T>
void InvertableBinaryTree<T>::swap(TreeNode<T> *parent) {
    TreeNode<T> *tmp = parent->left;
    parent->left = parent->right;
    parent->right = tmp;
}

template<typename T>
void InvertableBinaryTree<T>::invert(TreeNode<T> *root) {
    if(isLeaf(root)) return;
    if(root->left != null)
        invert(root->left);
    if(root->right != null)
        invert(root->right);
    swap(root);
}

#endif
