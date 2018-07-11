#include <iostream>
#include "linked_list.h"
//#include "binary_tree.h"

using namespace std;

int main() {
    LinkedList list = LinkedList();
    cout << list.isEmpty() << endl;
    list.add(30);
    list.add(10);
    list.add(1, 20);
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(2) << endl;
    cout << list.get(3) << endl;
    list.remove(1);
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(2) << endl;
    cout << list.size() << endl;
    return 0;
}
