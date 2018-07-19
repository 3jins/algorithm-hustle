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

#endif //ALGORITHM_HUSTLE_VECTOR_UTIL_H
