#include <iostream>
#include <vector>
#include "mail22.cpp"

using namespace std;

int main() {
    vector<vector<int>> inputVectors = {
            {1, 2, 3, 7, 10},
            {-5, -3, 0, 1},
            {1, 4, 5, 6, 8, 9}
    };
    vector<int> inputIntegers = {
            7,
            0,
            10
    };
    int inputSize = inputVectors.size();

    /* Using loop */
    for(int i=0; i<inputSize; i++) {
        cout << (binarySearch(inputVectors[i], inputIntegers[i]) ? "True" : "False") << endl;
    }

    /* Using recursive */
    for(int i=0; i<inputSize; i++) {
        int haySize = inputVectors[i].size() / 2;
        int needle = haySize;
        setHayStack(inputVectors[i]);
        cout << (binarySearchRecursive(needle, haySize, inputIntegers[i]) ? "True" : "False") << endl;
    }


    return 0;
}
