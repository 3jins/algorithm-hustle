// 14:31 ~ 15:00
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int numPlayers = stages.size();

    unordered_map<int, int> numStageClears;
    for (int i = 0; i<numPlayers; i++) {
        numStageClears[stages[i]] += 1;
    }

    int numReachers = stages.size();
    priority_queue<pair<double, int>> failRates;
    for (int i = 1; i <= N; i++) {
//        cout << (double)numStageClears[i] / (double)numReachers << ", " << i << endl;
        failRates.push({(double)numStageClears[i] / (double)numReachers, numPlayers - i});
        numReachers -= numStageClears[i];
    }

//    cout << endl;
    while(!failRates.empty()) {
//        cout << failRates.top().first << ", " << failRates.top().second << endl;
//        answer.insert(answer.begin(), failRates.top().second);
        answer.push_back(numPlayers - failRates.top().second);
        failRates.pop();
    }

    return answer;
}