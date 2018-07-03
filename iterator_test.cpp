#include <iostream>
#include <vector>

using namespace std;

void testVector() {
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int>::iterator iter;

    for(iter = v.begin(); iter != v.end(); iter++) {
        cout << iter.base() << ": " << *iter.base() << endl;
    }
}
