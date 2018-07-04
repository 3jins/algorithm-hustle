#include <iostream>
//#include "mail10.cpp"
//#include "mail11.cpp"
#include "mail12.cpp"

using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    productAllExceptSelf(arr, sizeof(arr) / sizeof(int));
    return 0;
}

