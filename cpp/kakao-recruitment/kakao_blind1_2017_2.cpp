// 16:47 ~ 17:51
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Record {
public:
    int score;
    char bonus;
    char option;
};

vector<Record *> parseDartResult(string dartResult) {
    int strLen = dartResult.length();
    int flag = 0;
    vector<Record *> parsed;
    Record *record;
    for (int i = 0; i < strLen; i++) {
        switch (flag) {
            case 0:
                record = new Record();
                if(dartResult[i] == '1' && dartResult[i + 1] == '0') {
                    record->score = 10;
                    i++;
                } else {
                    record->score = dartResult[i] - '0';
                }
                flag++;
                break;
            case 1:
                record->bonus = dartResult[i];
                if (i == strLen - 1) {
                    parsed.emplace_back(record);
                } else {
                    flag++;
                }
                break;
            case 2:
                if (dartResult[i] == '*' || dartResult[i] == '#') {
                    record->option = dartResult[i];
                    flag = 0;
                    parsed.emplace_back(record);
                } else {
                    parsed.emplace_back(record);
                    record = new Record();
                    if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
                        record->score = 10;
                        i++;
                    } else {
                        record->score = dartResult[i] - '0';
                    }
                    flag = 1;
                }
                break;
        }
    }
    return parsed;
}

int solution(string dartResult) {
    int total = 0;
    bool starPrize = false;
    vector<Record *> parsed = parseDartResult(dartResult);

    for (int i = 2; i >= 0; i--) {
        // score
        int curScore = parsed[i]->score;

        // bonus
        switch (parsed[i]->bonus) {
            case 'D':
                curScore *= curScore;
                break;
            case 'T':
                curScore *= curScore * curScore;
                break;
        }

        // option
        if (starPrize) {
            curScore *= 2;
            starPrize = false;
        }
        if (parsed[i]->option == '#') {
            curScore *= -1;
        } else if (parsed[i]->option == '*') {
            curScore *= 2;
            starPrize = true;
        }

//        cout << curScore << endl;
        total += curScore;
    }

    return total;
}