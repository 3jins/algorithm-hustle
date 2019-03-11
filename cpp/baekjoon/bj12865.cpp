#include <vector>
#include <algorithm>

using namespace std;

int optimizeKnapsack(int maxWeight, vector<vector<int>> items) {
    int numItems = items.size() - 1;
    vector<vector<int>> valueSums;
    valueSums.emplace_back(vector<int>(maxWeight + 1, 0)); // initialize

    for (int i = 1; i <= numItems; i++) {
        vector<int> valueSumsRow;
        for (int w = 0; w <= maxWeight; w++) {
            if (items[i][0] > w)
                valueSumsRow.emplace_back(valueSums[i - 1][w]);
            else
                valueSumsRow.emplace_back(max(valueSums[i - 1][w], valueSums[i - 1][w - items[i][0]] + items[i][1]));
        }
        valueSums.emplace_back(valueSumsRow);
    }

    int maxValue = 0;
    for (int i = 0; i <= numItems; i++) {
        int rowMax = *max_element(valueSums[i].begin(), valueSums[i].end());
        if (rowMax > maxValue) maxValue = rowMax;
    }

    return maxValue;
}