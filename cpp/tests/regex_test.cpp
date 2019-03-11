#include <iostream>
#include <string>
#include <regex>
#include "../utils/vector_util.h"

using namespace std;

void test1() {
    string test = "https://enhanced.kr/nav/Blog/tech?tag=algorithm";
    // .kr => .com
    // tech => life
    // algorithm => places
    regex tester("https?://enhanced(\\.[a-z]+)/nav/Blog/[a-z]+\\?tag=[a-z]+");
    cout << regex_match(test, tester) << endl;
}

void test2() {
    const string test = "1D2S#10S";
        regex tester("([0-9]{1,2})([A-Z])([*#]?)");
    smatch match;
    if(regex_search(test.begin(), test.end(), match, tester)) {
        cout << match[0] << endl;
        cout << match[1] << " / " << match[2] << " / " << match[3] << endl;
    }
}
