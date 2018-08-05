#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<int> cores) {
    int numCores = cores.size();
    int spentTime = 0;
    int workIdx = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < numCores; i++) {
        pq.push({cores[i] + spentTime, i});
        if (++workIdx == n) return i + 1;
    }
    while (true) {
        pair<int, int> finishedWork = pq.top();
        pq.pop();
        finishedWork.first += cores[finishedWork.second];
        pq.push(finishedWork);
        if (++workIdx == n) return finishedWork.second + 1;
    }
}
