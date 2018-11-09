#include <string>
#include <vector>

#define MAX 2500
#define DIVISOR 1000000007

using namespace std;

int solution(int n) {
    if (n % 2 == 1) return 0;
    n /= 2;
    long long numTiles[MAX] = {1, 3};
    long long sumNumTiles = 4;

    for (int i = 2; i <= n; i++) {
        numTiles[i] = numTiles[i - 1] + 2 * sumNumTiles;
        sumNumTiles += numTiles[i];
        numTiles[i] %= DIVISOR;
        sumNumTiles %= DIVISOR;
    }

    return numTiles[n];
}