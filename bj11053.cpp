#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seqSize;
vector<int> seq;
vector<int> lis;

/* test */
void printLIS() {
    int lisSize = lis.size();
    for(int i=0; i<lisSize; i++) {
        cout << lis[i] << " ";
    }
    cout << endl;
}

void getInputs() {
    cin >> seqSize;
    for (int i = 0; i < seqSize; i++) {
        int tmp;
        cin >> tmp;
        seq.emplace_back(tmp);
    }
}

void completeLIS() {
    lis.emplace_back(seq[0]);
    for (int i = 1; i < seqSize; i++) {
        if (seq[i] > lis.back()) {
            lis.emplace_back(seq[i]);
        } else {
            vector<int>::iterator iterator = lower_bound(lis.begin(), lis.end(), seq[i]);
            *iterator = seq[i];
        }
    }
}

void printLISSize() {
    getInputs();
    completeLIS();
    cout << lis.size() << endl;
}
