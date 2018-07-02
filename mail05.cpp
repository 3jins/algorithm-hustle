#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printTargetComb(vector<int> inputs, int target) {
    unordered_map<int, int> map;
    int sizeInput = inputs.size();

    for(int i=0; i<sizeInput; i++) {
        if(map.find(inputs[i]) != map.end()) {  // map에 inputs[i]가 있는지 확인. 배열에는 이런 함수가 없기 때문에 쓰기 애매하다.
            cout << i << ", " << map[inputs[i]] << endl;
        }
        map[target - inputs[i]] = i;
    }
}