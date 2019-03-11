// 15:53 ~ 16:28 (failed)
#include <iostream>
#include <vector>

using namespace std;

long long solution(vector<int> listNumTestTakers, int chiefCapability, int viceCapability) {
    long long count = 0;
    for(int numTestTaker : listNumTestTakers) {
        numTestTaker -= chiefCapability;
        count++;
        if(numTestTaker <= 0) continue;
        count += ((numTestTaker - 1) / viceCapability) + 1;
    }
    return count;
}
