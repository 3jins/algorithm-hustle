#include <iostream>
#include "mail17.cpp"

using namespace std;

int main() {
    vector<vector<int>> map = {
            {1, 0, 0, 1, 1, 0},
            {1, 0, 0, 1, 0, 0},
            {1, 1, 1, 1, 0, 0},
            {1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1}
    };
//    vector<vector<int>> map = {
//            {1, 1, 1, 0, 1, 0},
//            {0, 0, 0, 1, 0, 0},
//            {1, 1, 1, 1, 0, 0},
//            {1, 0, 0, 0, 0, 1},
//            {1, 1, 1, 1, 1, 1}
//    };
//    vector<vector<int>> map = {
//            {1, 1, 1, 1, 1, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0}
//    };
    pair<int, int> start = {0, 0};
    pair<int, int> finish = {0, 4};

    cout << getShortestDistance(map, start, finish) << endl;

    return 0;
}
