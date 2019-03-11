#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    void makeSet(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        if (rank[u] > rank[v]) merge(v, u);
        parent[u] = parent[v];
        if (rank[u] == rank[v]) rank[v]++;
    }
};

int getMax(vector<vector<int>> v) {
    int size = v.size();
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (v[i][1] > max) max = v[i][1];
    }
    return max;
}

void printResult(vector<int> parent) {
    int size = parent.size();
    int start = 1, end = 0;

    for (int i = 2; i <= size; i++) {
        if (parent[i] != parent[i - 1]) {
            end = i - 1;
            if (start != end) {
                cout << "{" << start << ", " << end << "}" << ", ";
            }
            start = i;
        }
    }
}

void printMergedArrays() {
    vector<vector<int>> input = {{3, 6},
                                 {1, 3},
                                 {2, 4}};
    int size = input.size();
    int max = getMax(input);
    DisjointSet ds;
    ds.makeSet(max);

    for (int i = 0; i < size; i++) {
        int start = input[i][0];
        int end = input[i][1];
        for (int j = start + 1; j <= end; j++) {
            ds.merge(j, start);
        }
    }
    for(int i = 1; i <= max; i++) {
        ds.find(i); // path compress
    }

    printResult(ds.parent);
}