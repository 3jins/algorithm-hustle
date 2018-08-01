#include <iostream>

#define IU_SOAR 3

using namespace std;

int logFloor(int n, int base) {
    int ret = 0;
    long long exp = 1;
    while (true) {
        exp *= base;
        if (n < exp) break;
        ret++;
    }
    return ret;
}

int pitchTest(int pitch, int soar, int add, int count) {
    if (pitch == 1 && soar == 0 && add == 0) return count + 1;
    if (soar * 2 < add) return count;
    if (soar < 0 || add < 0) return count;

    if (pitch % IU_SOAR == 0)
        count = pitchTest(pitch / 3, soar - 1, add, count);
    count = pitchTest(pitch - 1, soar, add - 1, count);
    return count;
}

int solution(int n) {
    int pitch = n;
    int soar = logFloor(n, IU_SOAR);
    int add = soar * 2;
//    cout << soar << add << endl;
    return pitchTest(pitch, soar, add, 0);
}