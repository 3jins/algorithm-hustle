#include <iostream>
//#include "mail10.cpp"
//#include "mail11.cpp"
//#include "mail12.cpp"
//#include "mail13.cpp"
#include "mail14.cpp"

using namespace std;

int main() {
    vector<vector<string>> inputs = {
            {"apple", "apps", "ape"},
            {"hawaii", "happy"},
            {"dog", "dogs", "doge"}
    };
    int numInputs = inputs.size();
    for (int i = 0; i < numInputs; i++) {
        cout << getLongestPrefixLen(inputs[i]) << endl;
    }

    return 0;
}
