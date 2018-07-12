#ifndef ALGORITHM_HUSTLE_LINKED_LIST_H
#define ALGORITHM_HUSTLE_LINKED_LIST_H

#define null 0

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* nextNode;
        Node(T data, Node *nextNode = null) {
            this->data = data;
            this->nextNode = nextNode;
        }
    };
    Node *head;
    Node *tail;
    int nodeCount;
public:
    LinkedList();
    T get(int index);
    void add(T data);
    void add(int index, T data);
    void set(int index, T data);
    void remove(int index);
    bool isEmpty();
    int size();
};

template <typename T>
LinkedList<T>::LinkedList() {
    tail = new Node(0);
    head = new Node(0, tail);
    nodeCount = 0;
}

template <typename T>
T LinkedList<T>::get(int index) {
    Node *curNode = head;
    for(int i=0; i<index; i++) {
        curNode = curNode->nextNode;
    }
    return curNode->data;
}

template <typename T>
void LinkedList<T>::add(T data) {
    Node *newNode = new Node(data, head->nextNode);
    newNode->nextNode = head->nextNode;
    head->nextNode = newNode;
    nodeCount++;
}

template <typename T>
void LinkedList<T>::add(int index, T data) {
    Node *newNode = new Node(data, head->nextNode);
    Node *curNode = head;
    for(int i=0; i<index; i++) {
        curNode = curNode->nextNode;
    }
    newNode->nextNode = curNode->nextNode;
    curNode->nextNode = newNode;
    nodeCount++;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    Node *curNode = head;
    for(int i=0; i<index; i++) {
        curNode = curNode->nextNode;
    }
    Node *tmp = curNode->nextNode;
    curNode->nextNode = curNode->nextNode->nextNode;
    tmp->nextNode = null;
    delete tmp;
    nodeCount--;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
    return nodeCount==0;
}

template <typename T>
int LinkedList<T>::size() {
    return nodeCount;
}

#endif
