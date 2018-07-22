#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int h = board.size();
    int w = board[0].size();

    board.insert(board.begin(), vector<int>(w, 0));
    for(int i=0; i < h + 1; i++) {
        board[i].insert(board[i].begin(), 0);
    }

    for(int i = 1; i < h + 1; i++) {
        for(int j = 1; j < w + 1; j++) {
            if(board[i][j] == 0) continue;
            vector<int> compares = {
                    board[i - 1][j - 1],
                    board[i - 1][j],
                    board[i][j - 1],
            };
            board[i][j] = *min_element(compares.begin(), compares.end()) + 1;
            if(answer < board[i][j]) {
                answer = board[i][j];
            }
        }
    }

    return answer * answer;
}