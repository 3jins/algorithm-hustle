#include <iostream>
//#include "mail10.cpp"
//#include "mail11.cpp"
//#include "mail12.cpp"
#include "mail13.cpp"

using namespace std;

int main() {
    vector<pair<vector<int>, int>> inputs = {
            {{-1, 3,  -1, 5,  4}, 2},
            {{2,  4,  -2, -3, 8}, 1},
            {{-5, -3, 1},         3}
    };
    int numInputs = inputs.size();
    for (int i = 0; i < numInputs; i++) {
        cout << getNth(inputs[i].first, inputs[i].second) << endl;
    }

    return 0;
}
