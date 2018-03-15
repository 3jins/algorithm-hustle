#include <iostream>
//#include "mail180219.cpp"
#include "mail180226.cpp"
#include "dp_fibonacci.cpp"

using namespace std;

int main() {
//    printSumOfEvenFibonacci();
    int result = getFibonacci(10);
    cout << (result < 0 ? "error" : to_string(result)) << endl;
    result = getFibonacci(8);
    cout << (result < 0 ? "error" : to_string(result)) << endl;
    result = getFibonacci(40);
    cout << (result < 0 ? "error" : to_string(result)) << endl;
    return 0;
}

