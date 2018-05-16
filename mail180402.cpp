#include <iostream>
#include <vector>

using namespace std;

vector<string> splitString(string s, char token) {
    vector<string> result;
    int lenStr = s.size();
    string buff = "";
    for(int i = 0; i < lenStr; i++) {
        if(s[i] == token) {
            result.emplace_back(buff);
            buff = "";
            continue;
        }
        buff += s[i];
    }
    result.emplace_back(buff);

    return result;
}

string invertString(string target) {
    string result = "";
    for(int i=0; i<target.size(); i++) {
        int targetLen = target.size();
        result += target[targetLen - i - 1];
    }
    return result;
}

void printInvertedString(string s) {
    vector<string> targets = splitString(s, ' ');
    string result = "";
    int numTargets = targets.size();
    for(int i=0; i<numTargets; i++) {
        string target = targets[i];
        result += invertString(target);
        if(i < numTargets - 1) {
            result += " ";
        }
    }
    cout << result << endl;
}