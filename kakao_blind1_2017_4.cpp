// 20:45 ~ 22:21 (1:36)
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

using ascpq = priority_queue<int, vector<int>, greater<int>>;

vector<string> split(string s, string delim) {
    vector<string> ret;
    while (true) {
        int cutIdx = s.find(delim);
        if (cutIdx < 0) {
            ret.emplace_back(s);
            break;
        }
        ret.emplace_back(s.substr(0, cutIdx));
        s = s.substr(cutIdx + delim.length());
    }
    return ret;
}

ascpq convertTimeTable(vector<string> timeTable) {
    ascpq times;
    int timeTableSize = timeTable.size();
    for (int i = 0; i < timeTableSize; i++) {
        vector<string> splitTime = split(timeTable[i], ":");
        times.push(stoi(splitTime[0]) * 60 + stoi(splitTime[1]));
    }
    return times;
}

string solution(int numBuses, int interval, int capacity, vector<string> timeTable) {
    int time = 540;
    ascpq timeTableQueue = convertTimeTable(timeTable);
    ascpq waitQueue;
    int latest = 1;

    for (int i = 0; i < numBuses; i++) {
        int count = 0;
        for (int j = 0; j < capacity; j++) {
            if(timeTableQueue.empty()) break;
            int arrivalTime = timeTableQueue.top();
            if (arrivalTime > time) continue;
            timeTableQueue.pop();
            waitQueue.push(arrivalTime);
            count++;
        }
        for (int j = 0; j < capacity; j++) {
            if (waitQueue.empty()) {
                latest = time + 1;
                break;
            }
            int onBusCrewTime = waitQueue.top();
            waitQueue.pop();
            if (latest < onBusCrewTime)
                latest = onBusCrewTime;
        }
        for (int j = capacity; j < count; j++) {
            timeTableQueue.push(waitQueue.top());
            waitQueue.pop();
        }
        time += interval;
    }
    latest -= 1;

    int hour = latest / 60;
    int minute = latest % 60;
    string hourStr = (hour < 10 ? "0" + to_string(hour) : "" + to_string(hour));
    string minuteStr = (minute < 10 ? "0" + to_string(minute) : "" + to_string(minute));
    return hourStr + ":" + minuteStr;
}