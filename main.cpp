#include <iostream>
//#include "mail10.cpp"
//#include "mail11.cpp"
//#include "mail12.cpp"
//#include "mail13.cpp"
//#include "mail14.cpp"
#include <list>
#include <vector>
#include "mail15.cpp"

using namespace std;

int main() {
    int numInputs = 3;
    list<int> inputLists[numInputs] = {
            {1, 2, 3, 4, 5},
            {1, 2, 3},
            {1}
    };
    int inputNs[numInputs] = {2, 3, 1};

    for (int i = 0; i < numInputs; i++) {
        list<int> outputList = eliminateNth(inputLists[i], inputNs[i]);
        if(outputList.size() == 0) {
            cout << "null" << endl;
            continue;
        }
        list<int>::iterator iter;
        for (iter = outputList.begin(); iter != outputList.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }

    return 0;
}
