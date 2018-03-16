#include <iostream>
#include <vector>

using namespace std;

/* Get integer vector that only contains fibonacci values smaller than N */
vector<int> getNeededFibonacciVector(int N) {
    vector<int> fibonacci = {1, 1}; // It doesn't matter if first element is 0 or 1.
    int i = 1;
    while (fibonacci[i] < N) {
        fibonacci.push_back(fibonacci[i] + fibonacci[i - 1]);
        i++;
    }
    fibonacci.pop_back();
    return fibonacci;
}

int getSumOfEvenFibonacci(int N) {
    vector<int> fibonacci = getNeededFibonacciVector(N);
    int idx = fibonacci.size();
    int sum = 0;
    for (int i = 2; i < idx; i += 3) {
        sum += fibonacci[i];
    }

    return sum;
}