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
//#include "mail180409.cpp"
#include "mail180416.cpp"
using namespace std;

int main() {
    vector<int> vec = {0, 5, 0, 3, -1};
//    vector<int> vec = {3, 0, 3};
    vector<int> result = moveZerosToBack(vec);
    for(int rst : result) {
        cout << rst << " ";
    }
    return 0;
}

