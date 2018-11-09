#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getBlockNo(long long n) {
    if(n == 1) return 0;
    int limit = floor(sqrt(n));
    int i = 2;
    while(i <= limit) {
        if(n % i == 0)
            return n / i;
        i++;
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin; i <= end; i++) {
        answer.emplace_back(getBlockNo(i));
    }
    return answer;
}