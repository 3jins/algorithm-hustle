#include <string>
#include <vector>

using namespace std;

int curState[3] = {0, 0, 0};
vector<vector<int>> answer;

void moveDisk(int from, int to, int amount) {
    if(amount == 1) {
        curState[from - 1]--;
        curState[to - 1]++;
        answer.emplace_back(vector<int>({from, to}));
    } else {
        moveDisk(from, 6 / (from * to), amount - 1);
        moveDisk(from, to, 1);
        moveDisk(6 / (from * to), to, amount - 1);
    }
}

vector<vector<int>> solution(int n) {
    curState[0] = n;
    moveDisk(1, 3, n);
    return answer;
}