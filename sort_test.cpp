#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] > b[2];
}

void test() {
    vector<vector<int>> v = {{9, 3, 0},
                             {7, 1, 3},
                             {2, 1, 8}};
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < 3; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}