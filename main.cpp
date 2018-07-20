#include <iostream>
#include <vector>
#include "mail19.cpp"

using namespace std;

int main() {
    vector<vector<int>> input = {
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5}
    };
    printClockwiseCenterward(input);

    return 0;
}
