// 14:00 ~ 14:30 (fail)
// 10만까지 되므로 NLogN. 정렬해놓고 이름을 바꾸든가 작년 3차 마지막 문제에 나온 자료구조를 쓰든가 해야 함.
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

typedef pair<string, string> pss;

vector<string> split(string s, string delim) {
    vector<string> ret;
    while (true) {
        int cutIdx = s.find(delim);
        if (cutIdx < 0) {
            ret.emplace_back(s);
            break;
        }
        ret.emplace_back(s.substr(0, cutIdx));
        s = s.substr(cutIdx + delim.length());
    }
    return ret;
}

void makeNickTable(vector<string> elements) {
    int numElements = elements.size();
    for (int i = 0; i < numElements; i++) {
        if(elements[0] != "Enter") continue;
        nickTable.push_back({elements[1], elements[2]});
    }
    for (int i = 0; i < numElements; i++) {
        nickTable.
    }
}

vector<string> formulate(vector<string> elements) {

}

string makeMessage(vector<string> elements) {
    string message = "";
    if (elements[0] == "Enter") {
        message += "들어왔습니다.";
    } else if (elements[0] == "Leave") {
        message += "나갔습니다.";
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pss> nickTable;

    vector<vector<string>> elements;
    for (singleRecord : record) {
        vector<string> element = split(singleRecord, " ");
        elements.push_back(element);
    }
    elements = makeNickTable(elements);
    elements = formulate(elements);
    for(element : elements) {
        string message = makeMessage(element);
        answer.push_back(message);
    }

    return answer;
}