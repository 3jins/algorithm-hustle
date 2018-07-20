#include <iostream>
#include <vector>
#include "mail20.cpp"

using namespace std;

int main() {
    vector<vector<int>> inputs = {
            {1, 2, 4, 0, 3},
            {1, 4, 5, 0, 3, 2},
            {1, 2, 2, 0}
    };
    int numInputs = inputs.size();
    for(int i=0; i < numInputs; i++) {
        cout << (canVisitAll(inputs[i]) ? "True" : "False") << endl;
    }
    return 0;
}
