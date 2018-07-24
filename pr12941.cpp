#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int result = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    int size = A.size();
    for(int i=0; i<size; i++) {
        result += A[i] * B[i];
    }
    return result;
}