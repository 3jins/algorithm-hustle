#include <string>
#include <vector>

using namespace std;

int countOnes(int n) {
    int cnt = 0;
    while(n > 0) {
        if(1 & n) cnt++;
        n = n >> 1;
    }
    return cnt;
}

int solution(int n) {
    int numOnes = countOnes(n);
    while(true) {
        if(numOnes == countOnes(++n)) return n;
    }
}
