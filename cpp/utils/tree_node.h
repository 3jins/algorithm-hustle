#ifndef ALGORITHM_HUSTLE_TREE_NODE_H
#define ALGORITHM_HUSTLE_TREE_NODE_H
#define null 0

template<typename T>
class TreeNode {
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data, TreeNode *left = null, TreeNode *right = null) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

#endif //ALGORITHM_HUSTLE_TREE_NODE_H
