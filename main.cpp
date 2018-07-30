#include <iostream>
#include <vector>
#include "bj12865.cpp"

using namespace std;

int main() {
    int numItems, maxWeight;
    vector<vector<int>> items = {{0, 0}};

    cin >> numItems >> maxWeight;
    for (int i = 0; i < numItems; i++) {
        int weight, value;
        cin >> weight >> value;
        items.emplace_back(vector<int>({weight, value}));
    }
    cout << optimizeKnapsack(maxWeight, items) << endl;
    return 0;
}
