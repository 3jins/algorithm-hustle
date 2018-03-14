#include <iostream>
#include <vector>

using namespace std;

/**
 * getLargestContinuousSum
 * @param input
 * @return
 */
int getLargestContinuousSum(vector<int> input) {
    int inputSize = input.size();
    int currentMax = input[0];
    int totalMax = input[0];
    for(int i=1; i<inputSize; i++) {
        currentMax = max(input[i], currentMax + input[i]);
        totalMax = max(totalMax, currentMax);
    }
    return totalMax;
}

/**
 * A unit test function for getLargestContinousSum
 * @param inputs answers
 * @return boolean
 */
bool testGetLargestContinuousSum(vector<vector<int>> inputs, vector<int> answers) {
    int testSize = inputs.size();
    if(testSize != answers.size()) {
        cout << "Size of the inputs and the answers are different!" << endl;
        return false;
    }

    for(int i=0; i<testSize; i++) {
        int largestContinuousSum = getLargestContinuousSum(inputs[i]);
        int answer = answers[i];
        if(largestContinuousSum != answer) {
            cout << "[" << i << "] " << largestContinuousSum << " " << answer << endl;
            return false;
        }
    }

    return true;
}

void printLargestContinuousSum() {
    vector<vector<int>> inputs = {
            {-1, 3, -1, 5},
            {-5, -3, -1},
            {2, 4, -2, -3, 8},
    };
    vector<int> answers = {7, -1, 9};
    bool testResult = testGetLargestContinuousSum(inputs, answers);
    if(testResult == 0) {
        cout << "fail" << endl;
    }
    else {
        cout << "success" << endl;
    }
}
