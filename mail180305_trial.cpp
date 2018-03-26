#include <iostream>
#include <vector>

using namespace std;

// 문자열벡터를 쭉 돌면서 다 출력
void printStringVector(vector<string> v) {
    int lenVector = v.size();

    for (int i = 0; i < lenVector; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// 문자열벡터의 각 원소에 괄호를 한겹씩 더 씌워서 리턴
vector<string> wrapEachElement(vector<string> v) {
    int lenVector = v.size();
    for (int i = 0; i < lenVector; i++) {
        v[i] = "(" + v[i] + ")";
    }
    return v;
}

// 두 문자열벡터를 붙일 수 있는 모든 조합을 리턴.
// 붙이는 순서는 고정.
vector<string> getConcatCombination(vector<string> v1, vector<string> v2) {
    int len1 = v1.size(), len2 = v2.size();
    vector<string> combinations = {};
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            combinations.push_back(v1[i] + v2[j]);
        }
    }
    return combinations;
}

void printParenthesisCom(int n) {
    vector<vector<string>> dp = {{""}, {"()"}};
    for (int i = 2; i <= n; i++) {
        vector<string> combinations = {};
        for (int j = 0; j < i; j++) {
            // dp[j]: 첫 덩어리
            // dp[i - j - 1]: 뒤에 따라오는 애들
            vector<string> leadingMass = wrapEachElement(dp[j]);
            vector<string> newCombinations = getConcatCombination(leadingMass, dp[i - j - 1]);
            combinations.insert(combinations.end(), newCombinations.begin(), newCombinations.end());
        }
        dp.push_back(combinations);
    }

    printStringVector(dp[n]);
}