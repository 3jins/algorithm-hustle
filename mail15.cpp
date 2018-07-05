#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

list<int> eliminateNth(list<int> inputList, int n) {
    stack<list<int>::iterator> nodeStack;
    list<int>::iterator iter;
    list<int>::iterator target;

    for(iter = inputList.begin(); iter != inputList.end(); iter++) {
        nodeStack.push(iter);
    }
    for(int i = 0; i < n; i++) {
        target = nodeStack.top();
        nodeStack.pop();
    }
    inputList.erase(target);

    return inputList;
}
