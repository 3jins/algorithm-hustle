#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int quotient = s / n;
    int remainder = s % n;
    if (!quotient) return {-1};
    for (int i = 0; i < n - remainder; i++) {
        answer.emplace_back(quotient);
    }
    for (int i = 0; i < remainder; i++) {
        answer.emplace_back(quotient + 1);
    }
    return answer;
}