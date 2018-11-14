// 11:05 ~
#include <iostream>
#include <vector>
#include "../utils/linked_list.h"

using namespace std;

LinkedList<int> make_linked_list(vector<int> data) {
    LinkedList<int> list = LinkedList<int>();
    int data_size = data.size();
    for (int i = data_size - 1; i >= 0; i--) {
        list.add(data[i]);
    }
    return list;
}

LinkedList<int> merge(LinkedList<int> left_list, LinkedList<int> right_list) {
    LinkedList<int> merged_list = LinkedList<int>();
    int left_size = left_list.size();
    int right_size = right_list.size();

    LLNode<int> *left_node = left_list.get_head()->next_node;
    LLNode<int> *right_node = right_list.get_head()->next_node;
    while(!(left_list.is_tail(left_node) && right_list.is_tail(right_node))) {
        if((!left_list.is_tail(left_node) && left_node->data < right_node->data) || right_list.is_tail(right_node)) {
            merged_list.append(left_node->data);
            left_node = left_node->next_node;
        } else {
            merged_list.append(right_node->data);
            right_node = right_node->next_node;
        }
    }

    return merged_list;
}

LinkedList<int> merge_sort_for_list(LinkedList<int> list) {
    int list_size = list.size();
    if (list_size <= 1) return list;
    LLNode<int> *head = list.get_head();

    LinkedList<int> left_list = LinkedList<int>();
    for (int i = 0; i < list_size / 2; i++) {
        head = head->next_node;
        left_list.append(head->data);
    }

    LinkedList<int> right_list = LinkedList<int>();
    for(int i=list_size / 2; i < list_size; i++) {
        head = head->next_node;
        right_list.append(head->data);
    }

    left_list = merge_sort_for_list(left_list);
    right_list = merge_sort_for_list(right_list);

    return merge(left_list, right_list);
}

void test() {
    vector<int> v = {9, 3, 0, 7, 1, 3, 9, 4, 1, 0, 2, 3};
    LinkedList<int> list = make_linked_list(v);
    LLNode<int> *head = list.get_head();
    cout << "input:  ";
    list.print_all();
    LinkedList<int> sorted_list = merge_sort_for_list(list);
    cout << "result: ";
    sorted_list.print_all();
}
