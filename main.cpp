#include <iostream>
//#include "mail180219.cpp"
//#include "dp_fibonacci.cpp"
//#include "dp_lis.cpp"
//#include "mail180226.cpp"
//#include "mail180305_trial.cpp"
//#include "mail180305.cpp"
//#include "mail180312.cpp"
//#include "mail180319_trial.cpp"
//#include "mail180319.cpp"
//#include "mail180326.cpp"
//#include "mail180402.cpp"
#include "mail180409.cpp"
using namespace std;

int main() {
    int arr1[] = {10, 5, 4, 3, -1};
    int arrSize = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> varr1;
    for (int i = 0; i < arrSize; i++) {
        varr1.emplace_back(arr1[i]);
    }
    vector<int> varr2 = {3, 3, 3};

    printSecondLarge(varr1);
    printSecondLarge(varr2);
    return 0;
}

