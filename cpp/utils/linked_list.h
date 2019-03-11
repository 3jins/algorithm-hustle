#ifndef ALGORITHM_HUSTLE_LINKED_LIST_H
#define ALGORITHM_HUSTLE_LINKED_LIST_H

#define null 0

template<typename T>
class LLNode {
public:
    T data;
    LLNode<T> *next_node;
    LLNode<T>(T data, LLNode<T> *next_node = null) {
        this->data = data;
        this->next_node = next_node;
    }
};

template<typename T>
class LinkedList {
private:
    LLNode<T> *head;
    LLNode<T> *tail;
    int node_count;
public:
    LinkedList();
    T get(int index);
    LLNode<T> *get_head();
    bool is_tail(LLNode<T> *node);
    T next(LLNode<T> *cur_node);
    void add(T data);
    void add(int index, T data);
    void append(T data);
    void set(int index, T data);
    void remove(int index);
    bool is_empty();
    int size();
    void print_all();
};

template<typename T>
LinkedList<T>::LinkedList() {
    tail = new LLNode<T>(0);
    head = new LLNode<T>(0, tail);
    node_count = 0;
}

template<typename T>
T LinkedList<T>::get(int index) {
    LLNode<T> *cur_node = head;
    for (int i = 0; i < index; i++) {
        cur_node = cur_node->next_node;
    }
    return cur_node->data;
}

template<typename T>
LLNode<T> *LinkedList<T>::get_head() {
    return head;
}

template<typename T>
bool LinkedList<T>::is_tail(LLNode<T> *node) {
    return node == tail;
}

template<typename T>
T LinkedList<T>::next(LLNode<T> *cur_node) {
    return cur_node->next_node;
}

template<typename T>
void LinkedList<T>::add(T data) {
    LLNode<T> *new_node = new LLNode<T>(data, head->next_node);
    new_node->next_node = head->next_node;
    head->next_node = new_node;
    node_count++;
}

template<typename T>
void LinkedList<T>::add(int index, T data) {
    LLNode<T> *new_node = new LLNode<T>(data);
    LLNode<T> *cur_node = head;
    for (int i = 0; i < index; i++) {
        cur_node = cur_node->next_node;
    }
    new_node->next_node = cur_node->next_node;
    cur_node->next_node = new_node;
    node_count++;
}

template<typename T>
void LinkedList<T>::append(T data) {
    LLNode<T> *new_node = new LLNode<T>(data);
    LLNode<T> *cur_node = head;
    for (int i = 0; i < node_count; i++) {
        cur_node = cur_node->next_node;
    }
    new_node->next_node = cur_node->next_node;
    cur_node->next_node = new_node;
    node_count++;
}

template<typename T>
void LinkedList<T>::remove(int index) {
    LLNode<T> *cur_node = head;
    for (int i = 0; i < index; i++) {
        cur_node = cur_node->next_node;
    }
    LLNode<T> *tmp = cur_node->next_node;
    cur_node->next_node = cur_node->next_node->next_node;
    tmp->next_node = null;
    delete tmp;
    node_count--;
}

template<typename T>
bool LinkedList<T>::is_empty() {
    return node_count == 0;
}

template<typename T>
int LinkedList<T>::size() {
    return node_count;
}

template<typename T>
void LinkedList<T>::print_all() {
    LLNode<T> *cur_node = head;
    while (true) {
        cur_node = cur_node->next_node;
        if (cur_node == tail) break;
        cout << cur_node->data << " ";
    }
    cout << endl;
}

#endif
