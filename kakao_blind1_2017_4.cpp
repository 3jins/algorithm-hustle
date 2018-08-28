// 20:45 ~ 22:21 (1:36)
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

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

vector<int> convertTimeTable(vector<string> timeTable) {
    vector<int> times;
    int timeTableSize = timeTable.size();
    for (int i = 0; i < timeTableSize; i++) {
        vector<string> splitTime = split(timeTable[i], ":");
        times.emplace_back(stoi(splitTime[0]) * 60 + stoi(splitTime[1]));
    }
    return times;
}

string solution(int numBuses, int interval, int capacity, vector<string> timeTable) {
    int time = 540;
    int latestTime = time;
    vector<int> intTimeTable = convertTimeTable(timeTable);
    int timeTableSize = intTimeTable.size();
    queue<int> waitQueue;
    int latest = 1;

    for (int i = 0; i < numBuses; i++) {
        for (int j = 0; j < timeTableSize; j++) {
            if (intTimeTable[j] <= time) {
                if (latest < intTimeTable[j]) {
                    latest = intTimeTable[j];
                }
                waitQueue.push(intTimeTable[j]);
                intTimeTable.erase(intTimeTable.begin() + j--);
                timeTableSize--;
            }
        }
        if (waitQueue.size() < capacity) {
            if (i + 1 == numBuses) latestTime = time;
            else latestTime = time + interval - 1;
        } else {
            latestTime = latest - 1;
        }
        time += interval;
        for (int i = 0; i < capacity; i++) {
            if (waitQueue.empty()) break;
            waitQueue.pop();
        }
    }

    int hour = latestTime / 60;
    int minute = latestTime % 60;
    string hourStr = (hour < 10 ? "0" + to_string(hour) : "" + to_string(hour));
    string minuteStr = (minute < 10 ? "0" + to_string(minute) : "" + to_string(minute));
    return hourStr + ":" + minuteStr;
}