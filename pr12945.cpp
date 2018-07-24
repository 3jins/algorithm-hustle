#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n <= 1) return n;
    int pprev = 0;
    int prev = 1;
    for(int i=2; i<=n; i++) {
        int cur = pprev + prev;
        pprev = prev % 1234567;
        prev = cur % 1234567;
    }

    return prev;
}