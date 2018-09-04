#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

void test() {
    string str = "123";
    int num = 321;
    cout << stoi(str) + num << endl;
}