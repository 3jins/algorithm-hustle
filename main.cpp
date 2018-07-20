#include <iostream>
#include <vector>
#include "vector_util.h"
#include "mail21.cpp"

using namespace std;

int main() {
    vector<int> input = {3, 1, 5, 6};
    printVector(quickSort(input), " ");
    return 0;
}
