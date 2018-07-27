#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorize(int target) {
    vector<int> primes;
    int limit = ceil(sqrt(target));
    for (int i = 2; i <= limit; i++) {
        while (target % i == 0) {
            target /= i;
            primes.emplace_back(i);
        }
    }
    return primes;
}

int getGCD(int a, int b) {
    int gcd = 1;
    vector<int> primes = factorize(a);
    vector<int>::iterator iter;
    for (iter = primes.begin(); iter < primes.end(); iter++) {
        int prime = *iter;
        if (b % prime == 0) {
            b /= prime;
            gcd *= prime;
        }
    }
    return gcd;
}

int getLCM(int a, int b) {
    int gcd = getGCD(a, b);
    return a * b / gcd;
}

int getLCM(vector<int> arr) {
    int lcm = arr[0];
    int arrSize = arr.size();
    for (int i = 1; i < arrSize; i++) {
        lcm = getLCM(lcm, arr[i]);
    }
    return lcm;
}

int solution(vector<int> arr) {
    int lcm = getLCM(arr);
    return lcm;
}
