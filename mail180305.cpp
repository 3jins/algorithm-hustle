#include <iostream>
#include <vector>

using namespace std;

void printParenthesisComRecursive(int cur, int end, int numOpen, string result) {
    if (cur == end) {
        cout << result << " ";
        return;
    }
    int numClose = cur - numOpen;
    if (numOpen < end / 2) {
        printParenthesisComRecursive(cur + 1, end, numOpen + 1, result + "(");
    }
    if (numClose < numOpen) {
        printParenthesisComRecursive(cur + 1, end, numOpen, result + ")");
    }
}

void printParenthesisCom(int n) {
    int end = 2 * n;
    int numOpen = 1;
    string result = "(";

    printParenthesisComRecursive(1, end, numOpen, result);
    cout << endl;
}