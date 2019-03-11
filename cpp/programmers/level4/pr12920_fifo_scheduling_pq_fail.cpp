#include <string>
#include <vector>
#include <array>

#define MAX_NUM_CORES 10000

using namespace std;

class PQ {
private:
    int q[MAX_NUM_CORES][2];
    int pqSize = 0;
public:
    PQ() {
//        for (int i = 0; i < MAX_NUM_CORES; i++) {
//            q[i][0] = 0;
//            q[i][1] = 0;
//        }
    };

    int getParentIdx(int childIdx) {
        if (childIdx == 0) return -1;
        return (childIdx - 1) / 2;
    }

    int getLeftChildIdx(int parentIdx) {
        return parentIdx * 2 + 1;
    }

    int getRightChildIdx(int parentIdx) {
        return parentIdx * 2 + 2;
    }

    void push(int data[2]) {
        int curIdx = pqSize++;
        int parentIdx = getParentIdx(curIdx);
        q[curIdx][0] = data[0];
        q[curIdx][1] = data[1];
        cout << q[parentIdx][0] << ", " << q[curIdx][0] << endl;
        while (curIdx > 0 && q[parentIdx][0] > q[curIdx][0]) {
            int tmp[2];
            tmp[0] = q[parentIdx][0];
            tmp[1] = q[parentIdx][1];
            q[parentIdx][0] = q[curIdx][0];
            q[parentIdx][1] = q[curIdx][1];
            q[curIdx][0] = tmp[0];
            q[curIdx][1] = tmp[1];
            curIdx = parentIdx;
            parentIdx = getParentIdx(curIdx);
        }
    };

    int* top() {
        return q[0];
    }

    void pop() {
        int parentIdx = 0;
        int leftChildIdx = getLeftChildIdx(parentIdx);
        int rightChildIdx = getRightChildIdx(parentIdx);
        int curIdx = leftChildIdx;
        if(q[leftChildIdx][0] > q[rightChildIdx][0])
            curIdx = rightChildIdx;
        while (curIdx < pqSize) {
            q[parentIdx][0] = q[curIdx][0];
            q[parentIdx][1] = q[curIdx][1];
            parentIdx = curIdx;
            leftChildIdx = getLeftChildIdx(parentIdx);
            rightChildIdx = getRightChildIdx(parentIdx);
            curIdx = leftChildIdx;
            if(q[leftChildIdx][0] > q[rightChildIdx][0])
                curIdx = rightChildIdx;
        }
        pqSize--;
    }
};

int solution(int n, vector<int> cores) {
    int numCores = cores.size();
    int spentTime = 0;
    int workIdx = 0;

    PQ pq;
    for (int i = 0; i < numCores; i++) {
        int work[2] = {cores[i] + spentTime, i};
        pq.push(work);
        if (++workIdx == n) return i + 1;
    }
    while (true) {
        int finishedWork[2];
        finishedWork[0] = pq.top()[0];
        finishedWork[1] = pq.top()[1];
        pq.pop();
        finishedWork[0] += cores[finishedWork[1]];
        cout << workIdx + 1 << ") " << finishedWork[1] << " " << finishedWork[0] << endl;
        pq.push(finishedWork);
        if (++workIdx == n) return finishedWork[1] + 1;
    }


//    array<array<int, 2>, 3> a = array<array<int, 2>, 3>();
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 2; j++) {
//            a[i][j] = i * 10 + j;
//        }
//    }
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 2; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }


}
