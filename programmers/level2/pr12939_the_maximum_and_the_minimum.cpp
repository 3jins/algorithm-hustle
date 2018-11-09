#include <string>
#include <vector>
#include <algorithm>
#include "../../utils/string_util.h"

using namespace std;

string solution(string s) {
    vector<string> inputs = split(s, " ");
    vector<int> converted;
    int numInputs = inputs.size();

    for (int i = 0; i < numInputs; i++) {
        if(inputs[i][0] == '-') {
            converted.emplace_back(-stoi(inputs[i].substr(1)));
        } else {
            converted.emplace_back(stoi(inputs[i]));
        }
    }

    return to_string(*min_element(converted.begin(), converted.end())) + " " + to_string(*max_element(converted.begin(), converted.end()));
}
