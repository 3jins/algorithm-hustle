#include <string>
#include <regex>
#include "vector_util.h"

using namespace std;

void test() {
    string test = "https://enhanced.kr/nav/Blog/tech?tag=algorithm";
    // .kr => .com
    // tech => life
    // algorithm => places
    regex tester("https?://enhanced(\\.[a-z]+)/nav/Blog/[a-z]+\\?tag=[a-z]+");
    cout << regex_match(test, tester) << endl;
    cout << regex_replace(test, tester, "$1", "com") << endl;
}