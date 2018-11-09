// 15:48 ~
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> integers, int k) {
    int num_integers = integers.size();
    vector<int> tmp(k, 0);
    for (int i = 0; i < k; i++) {
        tmp[i] = integers[i];
    }
    for (int i = 0; i < num_integers - k; i++) {
        integers[i] = integers[i + k];
    }
    for (int i = 0; i < k; i++) {
        integers[num_integers - k + i] = tmp[i];
    }
    return integers;
}
