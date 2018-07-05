#include <iostream>
#include "mail16.cpp"

using namespace std;

int main() {
    int numInputs = 2;
    list<int> inputLists1[numInputs] = {
            {1, 2, 3},
            {1, 3, 5, 6}
    };
    list<int> inputLists2[numInputs] = {
            {1, 2, 3},
            {2, 4}
    };

    for (int i = 0; i < numInputs; i++) {
        list<int> outputList = mergeLists(inputLists1[i], inputLists2[i]);

        list<int>::iterator iter;
        for (iter = outputList.begin(); iter != outputList.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }

    return 0;
}
