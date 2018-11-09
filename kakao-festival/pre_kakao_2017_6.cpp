#include <vector>
#include <vector>
#include "../utils/vector_util.h"

using namespace std;

#define null 0

template<typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode *> children;

    TreeNode(T data, vector<TreeNode *> children = {}) {
        this->data = data;
        this->children = children;
    }
};

template<typename T>
class Tree {
private:
    TreeNode<T> *root;
public:
    Tree(T rootData = 0);

    TreeNode<T> *getRoot();

    TreeNode<T> *getLastChild(TreeNode<T> *parent);

    void addChild(TreeNode<T> *parent, T data = null, int idx = 0);

    int buildTree(TreeNode<T> *root, vector<vector<T>> data);

    bool isLeaf(TreeNode<T> *node);

    vector<T> preorderTraversal(TreeNode<T> *root);
};

template<typename T>
Tree<T>::Tree(T rootData) {
    root = new TreeNode<T>(rootData);
}

template<typename T>
TreeNode<T> *Tree<T>::getRoot() {
    return root;
}

template<typename T>
TreeNode<T> *Tree<T>::getLastChild(TreeNode<T> *parent) {
    vector<TreeNode<T>> children = parent->children;
    return children.back();
}

template<typename T>
void Tree<T>::addChild(TreeNode<T> *parent, T data, int idx) {
    (parent->children).insert((parent->children).begin() + idx, new TreeNode<T>(data));
}

template<typename T>
int Tree<T>::buildTree(TreeNode<T> *root, vector<vector<T>> data) {
    int dataSize = data.size();
    if (dataSize == 0) return -1;
    for (int i = 0; i < dataSize; i++) {
        if (data[i][0] == root->data) {
            addChild(root, data[i][1]);
            data.erase(data.begin() + i);
//            cout << data[i][0] << " " << data[i][1] << endl;
            cout << getLastChild(root)->data << endl;
//            buildTree(getLastChild(root), data[i][1]);
        }
    }
    return 0;
}

template<typename T>
vector<T> Tree<T>::preorderTraversal(TreeNode<T> *root) {
    vector<T> ret = {};
    if (root != null) {
        ret.emplace_back(root->data);
        vector<T> children = root->children;
        typename vector<TreeNode<T>>::iterator iter;
        for (iter = children.begin(); iter != children.end(); iter++) {
            vector<T> child = preorderTraversal(*iter);
            ret.insert(ret.end(), child.begin(), child.end());
        }
    }
    return ret;
}

template<typename T>
bool isLeaf(TreeNode<T> *node) {
    return ((node->children).size() == 0);
}

int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
    int answer = 0;

    Tree<int> *tree = new Tree<int>(1);
    tree->buildTree(tree->getRoot(), g1);
//    printVector(tree->preorderTraversal(tree->getRoot()), " ");
    return answer;
}
