#include <string>
#include <vector>
#include "../../utils/string_util.h"

using namespace std;

string toLower(string s) {
    string::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++) {
        if(*iter >= 'A' && *iter <= 'Z')
            *iter += 'a' - 'A';
    }
    return s;
}

string solution(string s) {
    string answer = "";
    s = toLower(s);
    vector<string> fragments = split(s, " ");
    vector<string>::iterator iter;
    for(iter = fragments.begin(); iter != fragments.end(); iter++) {
        if((*iter)[0] >= 'a' && (*iter)[0] <= 'z')
            (*iter)[0] += 'A' - 'a';
        answer += *iter;
        if(iter + 1 == fragments.end()) break;
        answer += ' ';
    }
    return answer;
}