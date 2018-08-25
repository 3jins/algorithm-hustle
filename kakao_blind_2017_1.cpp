// 16:30 ~ 16:45
#include <iostream>
#include <vector>

using namespace std;

string convertMap(int deca) {
    string mapRow = "";
    while(deca > 0) {
        if(deca % 2 == 1) {
            mapRow = "#" + mapRow;
        } else {
            mapRow = " " + mapRow;
        }
        deca /= 2;
    }
    return mapRow;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> map;
    int arrSize = arr1.size();

    for (int i = 0; i < arrSize; i++) {
        map.emplace_back(convertMap(arr1[i] | arr2[i]));
    }
    return map;
}