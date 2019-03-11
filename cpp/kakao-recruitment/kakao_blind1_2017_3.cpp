// 17:58 ~ 18:08, 19:42 ~ 20:25 (53')
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string toLowerCase(string str) {
    int strLen = str.length();
    for (int i = 0; i < strLen; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int runTime = 0;
    bool isHit = false;
    vector<string> cache;
    int curCacheSize = 0;
    int numCities = cities.size();

    for (int i = 0; i < numCities; i++) {
        string cityName = toLowerCase(cities[i]);
        vector<string>::iterator iter;
        for (iter = cache.begin(); iter != cache.end(); iter++) {
            if (*iter == cityName) {
                cache.erase(iter);
                runTime++;
                isHit = true;
                break;
            }
        }
        cache.push_back(cityName);
        if (isHit) {
            isHit = false;
            continue;
        }
        runTime += 5;
        curCacheSize++;
        if (curCacheSize > cacheSize) cache.erase(cache.begin());
    }
    return runTime;
}