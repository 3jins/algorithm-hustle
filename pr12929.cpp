#include <string>
#include <vector>

using namespace std;

int limit = 0;

int getNumProperParenthesises(int count, int opens, int closes) {
    if(opens > limit / 2) return 0;
    if(opens < closes) return 0;
    if(count == limit) return 1;
    return getNumProperParenthesises(count + 1, opens + 1, closes) + getNumProperParenthesises(count + 1, opens, closes + 1);
}

int solution(int n) {
    limit = 2 * n;
    int opens = 1;
    int closes = 0;
    return getNumProperParenthesises(1, 1, 0);
}