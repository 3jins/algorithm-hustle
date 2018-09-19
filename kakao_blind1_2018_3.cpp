// 15:00 ~ 15:19 (fail)
// 어려움. 조합을 구하는 법을 찾아야 함. 자료구조 문제일지도 모름.
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> relationT;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int numRows = relation.size();
    int numAttrs = relation[0].size();

    for (int j = 0; j < numAttrs; j++) {
        vector<string> attribute;
        for (int i = 0; i < numRows; i++) {
            attribute.push_back(relation[i][j]);
        }
        relationT.push_back(attribute);
    }

    for (int i = 1; i <= numAttrs; i++) {    // 1개 뽑기 ~ 8개 뽑기
        for (int j = 0; j < numAttrs; j++) {

        }
        isCandidate({i});
    }

    isCandidate({i, j});


    return answer;
}