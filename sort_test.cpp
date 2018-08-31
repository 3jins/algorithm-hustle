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

class MyObj {
public:
    int i1;
    int i2;

    MyObj(int i1, int i2) {
        this->i1 = i1;
        this->i2 = i2;
    }
};

bool cmp2(MyObj *a, MyObj *b) {
    return (a -> i1 < b -> i1);
}

void test2() {
    vector<MyObj *> v;
    MyObj *o1 = new MyObj(3, 7);
    MyObj *o2 = new MyObj(2, 9);
    MyObj *o3 = new MyObj(7, 13);
    v.push_back(o1);
    v.push_back(o2);
    v.push_back(o3);
    sort(v.begin(), v.end(), cmp2);
    for(int i=0; i<v.size(); i++) {
        cout << v[i]->i1 << ", " << v[i]->i2 << " / " << endl;
    }
}

//bool cmp(MyObj a, MyObj b) {
//    return (a.i1 < b.i1);
//}
//
//void test3() {
//    vector<MyObj> v;
//    MyObj o1 = MyObj(3, 7);
//    MyObj o2 = MyObj(2, 9);
//    MyObj o3 = MyObj(7, 13);
//    v.push_back(o1);
//    v.push_back(o2);
//    v.push_back(o3);
//    sort(v.begin(), v.end(), cmp);
//    for(int i=0; i<v.size(); i++) {
//        cout << v[i]->i1 << ", " << v[i]->i2 << " / " << endl;
//    }
//}
