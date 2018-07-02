#include <iostream>
#include <vector>

using namespace std;

vector<int> moveZerosToBack(vector<int> vec) {
    int vecSize = vec.size();
    vector<int> zeros;
    for (int i = 0; i < vecSize; i++) {
        if (vec[i] == 0) {
            zeros.insert(zeros.begin(), i);
        }
    }
    for(int zero : zeros) {
        vec.erase(vec.begin() + zero);
        vec.emplace_back(0);
    }
    return vec;
}