#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> seq) {
    int lenSeq = seq.size();
    for (int i = 0; i < lenSeq; i++) {
        cout << seq[i] << " ";
    }
    cout << endl;
}

void printLIS(vector<int> seq) {
    vector<int> LIS = {seq[0]};
    int lenSeq = seq.size();
    int lenLIS = LIS.size();

    for (int i = 1; i < lenSeq; i++) {
        if (seq[i] > LIS.back()) {
            LIS.push_back(seq[i]);
            lenLIS++;
        }
        else {
            vector<int>::iterator iterator = lower_bound(LIS.begin(), LIS.end(), seq[i]);
            *iterator = seq[i];
        }
    }
    printVector(LIS);
}



