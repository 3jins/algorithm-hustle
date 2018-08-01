#include <string>
#include <vector>

using namespace std;

long long factorial(int n) {
    long long ret = 1;
    while (n > 1) ret *= n--;
    return ret;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    for (int i = 1; i <= n; i++) {
        people.emplace_back(i);
    }

    long long kCopy = k;
    int idx = 1;
    long long factorialVal = factorial(n - idx);
    while (n > idx) {
        answer.emplace_back((kCopy - 1) / factorialVal);
        kCopy = kCopy % factorialVal == 0 ? factorialVal : kCopy % factorialVal;
        factorialVal /= (n - idx);
        idx++;
    }

    for (int i = 0; i < n - 1; i++) {
        int idx = answer[i];
        answer[i] = people[idx];
        people.erase(people.begin() + idx);
    }
    answer.emplace_back(people[0]);

    return answer;
}