// 9:53 ~ 11:04 - 10'(카톡)
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

typedef pair<int, int> pii;

vector<pii> convertLinesToLogs(vector<string> lines) {
    vector<pii> logs = {{1, 1}};
    for (string line : lines) {
        const string logLine = line;
        regex tester("(2016-09-15 ([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}) ([0-9](.[0-9]*)?)s)");
        smatch match;
        int endTime = 0;
        int startTime = 0;
        if (regex_search(logLine.begin(), logLine.end(), match, tester)) {
            endTime =
                    stoi(match[2]) * 3600 * 1000 + stoi(match[3]) * 60 * 1000 + stoi(match[4]) * 1000 + stoi(match[5]);
            startTime = endTime - stof(match[6]) * 1000 + 1;
        }
        logs.emplace_back(pii(startTime, endTime));
    }
    return logs;
}

int solution(vector<string> lines) {
    int maxThroughput = 1;
    vector<pii> logs = convertLinesToLogs(lines);
    int numLogs = logs.size();
    for (int i = numLogs - 1; i > 0; i--) {
        int throughput = 1;
        for (int j = i - 1; j >= 0; j--) {
            if(logs[j].second >= logs[i].first - 999) {
                throughput++;
            }
        }
        if(throughput > maxThroughput) maxThroughput = throughput;
    }
    return maxThroughput;
}