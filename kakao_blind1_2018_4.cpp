// 15:19 ~ 16:06 (fail)
// 복잡함. 답을 못 맞추겠음.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<int> foodTimes, long long k) {
    int answer;
    int numFoodKinds = foodTimes.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 0; i < numFoodKinds; i++) {
        pq.push({foodTimes[i], i});
    }

    int timeGone = 0;
    int longestEatingTime = 0;
    while(timeGone + (pq.top().first - longestEatingTime) * numFoodKinds <= k) {
        pii foodEaten = pq.top();
        pq.pop();
        timeGone += (foodEaten.first - longestEatingTime) * numFoodKinds--;
        longestEatingTime += (foodEaten.first - longestEatingTime);
//        cout << timeGone << ", " << longestEatingTime << ", " << foodEaten.second << endl;
        answer = ((foodEaten.second + 1) + (k - timeGone + 1)) % foodTimes.size();
    }

    return answer;
}