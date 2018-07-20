#include <iostream>
#include <vector>
#include "vector_util.h"

using namespace std;

bool isZeroExist(vector<int> v) {
    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++) {
        if(*iter == 0) return true;
    }
    return false;
}

bool canVisitAll(vector<int> v) {
    int curIdx = 0;
    int visitCount = 0;
    int vectorSize = v.size();
    if(!isZeroExist(v)) return false;
    while(visitCount++ < vectorSize) {
        if(v[curIdx] == -1) return false;
        if(v[curIdx] == 0 && visitCount == vectorSize) return true;
        int nextIdx = v[curIdx];
        v[curIdx] = -1;
        curIdx = nextIdx;
    }
    return false;
}
