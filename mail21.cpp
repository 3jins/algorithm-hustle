#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> v) {
    int vectorSize = v.size();
    if(vectorSize <= 1) return v;
    int pivot = v[0];
    vector<int> minor;
    vector<int> major;
    for(int i=1; i < vectorSize; i++) {
        if(v[i] < pivot) {
            minor.emplace_back(v[i]);
        } else {
            major.emplace_back(v[i]);
        }
    }
    minor = quickSort(minor);
    major = quickSort(major);
    minor.emplace_back(pivot);
    minor.insert(minor.end(), major.begin(), major.end());
    return minor;
}
