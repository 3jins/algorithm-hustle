#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> mergeLists(list<int> list1, list<int> list2) {
    list<int>::iterator iter1 = list1.begin();
    list<int>::iterator iter2 = list2.begin();
    list<int> outputList;

    while(iter1 != list1.end() && iter2 != list2.end()) {
        if(*iter1 < *iter2) {
            outputList.emplace_back(*(iter1++));
        }
        else {
            outputList.emplace_back(*(iter2++));
        }
    }

    if(iter1 == list1.end()) {
        while(iter2 != list2.end()) outputList.emplace_back(*(iter2++));
    }
    if(iter2 == list2.end()) {
        while(iter1 != list1.end()) outputList.emplace_back(*(iter1++));
    }

    return outputList;
}
