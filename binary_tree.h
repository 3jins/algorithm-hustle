#ifndef ALGORITHM_HUSTLE_BINARY_TREE_H
#define ALGORITHM_HUSTLE_BINARY_TREE_H

#include <vector>
#include "tree_node.h"

#define null 0

using namespace std;

template<typename T>
class BinaryTree {
private:
    TreeNode<T> *root;
public:
    BinaryTree(T rootData = 0);
    TreeNode<T> *getRoot();
    int addLeft(TreeNode<T> *parent, T data = null);
    int addRight(TreeNode<T> *parent, T data = null);
    void removeLeft(TreeNode<T> *parent);
    void removeRight(TreeNode<T> *parent);
    int buildTree(TreeNode<T> *root, vector<T> data, int idx = 0);
    bool isLeaf(TreeNode<T> *node);
    vector<T> preorderTraversal(TreeNode<T> *root);
    vector<T> inorderTraversal(TreeNode<T> *root);
    vector<T> postorderTraversal(TreeNode<T> *root);
};

template<typename T>
BinaryTree<T>::BinaryTree(T rootData) {
    root = new TreeNode<T>(rootData);
}

template<typename T>
TreeNode<T> *BinaryTree<T>::getRoot() {
    return root;
}

template<typename T>
int BinaryTree<T>::addLeft(TreeNode<T> *parent, T data) {
    if (parent->left != null)
        return -1;
    parent->left = new TreeNode<T>(data);
    return 0;
}

template<typename T>
int BinaryTree<T>::addRight(TreeNode<T> *parent, T data) {
    if (parent->right != null)
        return -1;
    parent->right = new TreeNode<T>(data);
    return 0;
}

template<typename T>
void BinaryTree<T>::removeLeft(TreeNode<T> *parent) {
    delete parent->left;
    parent->left = null;
}

template<typename T>
void BinaryTree<T>::removeRight(TreeNode<T> *parent) {
    delete parent->right;
    parent->right = null;
}

template<typename T>
int BinaryTree<T>::buildTree(TreeNode<T> *root, vector<T> data, int idx) {
    if (idx >= data.size()) return -1;
    if (root->data == null) root->data = data[idx];
    addLeft(root);
    if (buildTree(root->left, data, idx * 2 + 1) < 0) {
        removeLeft(root);
    }
    addRight(root);
    if (buildTree(root->right, data, idx * 2 + 2) < 0) {
        removeRight(root);
    }
    return 0;
}

template<typename T>
vector<T> BinaryTree<T>::preorderTraversal(TreeNode<T> *root) {
    vector<T> ret = {};
    if (root != null) {
        ret.emplace_back(root->data);
        vector<T> left = preorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        vector<T> right = preorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
    }
    return ret;
}

template<typename T>
vector<T> BinaryTree<T>::inorderTraversal(TreeNode<T> *root) {
    vector<T> ret = {};
    if (root != null) {
        vector<T> left = preorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.emplace_back(root->data);
        vector<T> right = preorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
    }
    return ret;
}

template<typename T>
vector<T> BinaryTree<T>::postorderTraversal(TreeNode<T> *root) {
    vector<T> ret = {};
    if (root != null) {
        vector<T> left = preorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        vector<T> right = preorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        ret.emplace_back(root->data);
    }
    return ret;
}

template<typename T>
bool isLeaf(TreeNode<T> *node) {
    return (node->left == null && node->right == null);
}

#endif
