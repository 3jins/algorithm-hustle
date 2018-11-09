#include <iostream>
#include <vector>

using namespace std;

vector<int> getLargest(vector<int> varr) {
    int varrSize = varr.size();
    vector<int> result = {0, varr[0]};
    for (int i = 1; i < varrSize; i++) {
        if (varr[i] > result[1]) {
            result[0] = i;
            result[1] = varr[i];
        }
    }
    return result;
}

void printSecondLarge(vector<int> varr) {
    vector<int> largest = getLargest(varr);
    varr.erase(varr.begin() + largest[0]);
    vector<int> second = getLargest(varr);
    if (second[1] == largest[1]) {
        cout << "Does not exist" << endl;
        return;
    }
    cout << second[1] << endl;
}