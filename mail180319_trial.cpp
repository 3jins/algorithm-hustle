#include <iostream>
#include <vector>

using namespace std;

void printTargetComb(vector<int> inputs, int target) {
    int sizeInputs = inputs.size();
    vector<int> results = {};
    while (target > 0) {
        target -= 2;
        results = {};
        for (int i = 0; i < sizeInputs; i++) {
            if (--inputs[i] == 0) {
                results.push_back(i);
            } else if (inputs[i] == target) {
                results.push_back(i);
            }
            if (results.size() == 2) {
                cout << results[0] << ", " << results[1] << endl;
                return;
            }
        }
    }
    cout << "Impossible" << endl;
    return;
}