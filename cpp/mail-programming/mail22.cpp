#include <iostream>
#include <vector>

using namespace std;

/* 1st way
 * Loop
 */
bool binarySearch(vector<int> v, int target) {
    int haySize = v.size();
    int needle = haySize;

    while(haySize > 0) {
        if(target == v[needle]) return true;
        haySize /= 2;
        if(target < v[needle]) {
            needle -= haySize;
        } else {
            needle += haySize;
        }
    }
    return false;
}


/* 2nd way
 * Recursive
 */
vector<int> hayStack;
void setHayStack(vector<int> v) {
    hayStack = v;
}

bool binarySearchRecursive(int needle, int haySize, int target) {
    if(target == hayStack[needle]) return true;
    if(haySize == 0) return false;
    haySize /= 2;
    if(target < hayStack[needle]) {
        return binarySearchRecursive(needle - haySize, haySize, target);
    } else {
        return binarySearchRecursive(needle + haySize, haySize, target);
    }
}
