#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVectorInt(vector<int> vec) {
    int vectorSize = vec.size();
    for (int i = 0; i < vectorSize; i++)
        cout << vec[i] << " ";
    cout << endl;
}

bool cmp(int a, int b) {
    return a > b;
}

int getNth(vector<int> vec, int n) {
    sort(vec.begin(), vec.end(), cmp);
    return vec[n - 1];
}
