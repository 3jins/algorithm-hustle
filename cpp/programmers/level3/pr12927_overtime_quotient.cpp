#include <string>
#include <vector>
#include <algorithm>

#define MAXN 20000;

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int numWorks = works.size();
    sort(works.begin(), works.end(), cmp);

    int sum = 0;
    for (int i = 0; i < numWorks; i++) {
        sum += works[i];
    }
    if (sum <= n) return 0;

    int idx = 0;
    while (n > 0) {
        while (works[0] == 0) {
            works.erase(works.begin());
            idx--;
        }
        while (works[idx] == works[idx + 1]) idx++;
        for (int i = 0; i <= idx; i++) {
            works[i]--;
            n--;
            if (n == 0) break;
        }
    }

    for (int i = 0; i < numWorks; i++) {
        answer += works[i] * works[i];
    }

    return answer;
}