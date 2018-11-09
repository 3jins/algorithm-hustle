#include <vector>
#include <iostream>

using namespace std;

void printIntVector(vector<int> v) {
    int vectorSize = v.size();
    for (int i = 0; i < vectorSize; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void productAllExceptSelf(int arr[], int arrSize) {
    vector<int> preOrder = {1};
    vector<int> postOrder = {1};
    vector<int> result;

    for (int i = 1; i < arrSize; i++) {
        preOrder.emplace_back(preOrder[i - 1] * arr[i - 1]);
        postOrder.emplace(postOrder.begin(), postOrder[0] * arr[arrSize - i]);
    }
//    printIntVector(preOrder);
//    printIntVector(postOrder);
    for (int i = 0; i < arrSize; i++) {
        result.emplace_back(preOrder[i] * postOrder[i]);
    }
    printIntVector(result);
}
