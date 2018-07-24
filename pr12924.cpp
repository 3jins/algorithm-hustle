#include <string>
#include <vector>

using namespace std;

int sum(int n) {
    return n / 2 * (n + 1);
}

int calcLimit(int n) {
    int ret = 1;
    while (ret++) {
        if(sum(ret) > n) break;
    }
    return ret;
}

int solution(int n) {
    int cnt = 0;
    int limit = calcLimit(n);
    for (int i = 1; i <= limit; i++) {
        if (i % 2 == 0) {
            if (n % i == 1 && n % (i / 2) == 0) cnt++;
        } else {
            if (n % i == 0) cnt++;
        }
    }
    return cnt;
}