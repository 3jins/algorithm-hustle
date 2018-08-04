#include <string>
#include <regex>
#include "vector_util.h"

using namespace std;

bool isLowerCase(char c) {
    if(c <= 'z' && c >= 'a') return true;
    return false;
}
string solution(string sentence) {
    cout << sentence << endl;
    int sentenceLength = sentence.length();
    for (int i = 0; i < sentenceLength; i++) {
        if(sentence.length() == 0) break;
        if(isLowerCase(sentence[i])) {
            char adChar = sentence[i];
            string rule1 = "([A-Z](";
            rule1 += adChar;
            rule1 += "[A-Z])+).*";
            string rule2 = "(";
            rule2 += adChar;
            rule2 += "[A-Z]+";
            rule2 += adChar;
            rule2 += ").*";
            cout << rule1 << endl;

            string ruleStr = rule1;
//            ruleStr += "|";
//            ruleStr += rule2;
            regex rule(ruleStr);

            string target = regex_replace(sentence, rule, "$1");
//            cout << target << endl;
            cout << sentence.replace(0, target.length(), "") << endl;
            i = 0;
        }
    }

    return "";
}