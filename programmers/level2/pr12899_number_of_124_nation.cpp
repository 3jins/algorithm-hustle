#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int no) {
    string answer = "";
    char digits[3] = {'4', '1', '2'};
    int remainder;
    while (no > 0) {
        remainder = no % 3;
        no /= 3;
        if (remainder == 0)
            no--;
        answer = digits[remainder] + answer;
    }
    return answer;
}
