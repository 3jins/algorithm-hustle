#ifndef ALGORITHM_HUSTLE_VECTOR_UTIL_H
#define ALGORITHM_HUSTLE_VECTOR_UTIL_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printVector(vector<T> v, string separator = "\n") {
    typename vector<T>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << separator;
    }
    cout << endl;
}

template<typename T>
vector<vector<T>> init2WdVector(vector<vector<T>> v, int w, int h, T initElem = 0) {
    for(int i=0; i<h; i++) {
        vector<T> tmp;
        for(int j=0; j<w; j++) {
            tmp.emplace_back(initElem);
        }
        v.emplace_back(tmp);
    }
    return v;
}

#endif //ALGORITHM_HUSTLE_VECTOR_UTIL_H
