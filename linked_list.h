#ifndef ALGORITHM_HUSTLE_LINKED_LIST_H
#define ALGORITHM_HUSTLE_LINKED_LIST_H

#define null 0

class LinkedList {
private:
    class Node {
    public:
        int data;
        Node* nextNode;
        Node(int data, Node *nextNode = null) {
            this->data = data;
            this->nextNode = nextNode;
        }
    };
    Node *head;
    Node *tail;
    int nodeCount;
public:
    LinkedList();
    int get(int index);
    void add(int data);
    void add(int index, int data);
    void set(int index, int data);
    void remove(int index);
    bool isEmpty();
    int size();
};

LinkedList::LinkedList() {
    tail = new Node(0);
    head = new Node(0, tail);
    nodeCount = 0;
}

int LinkedList::get(int index) {
    Node *curNode = head;
    for(int i=0; i<index; i++) {
        curNode = curNode->nextNode;
    }
    return curNode->data;
}

void LinkedList::add(int data) {
    Node *newNode = new Node(data, head->nextNode);
    newNode->nextNode = head->nextNode;
    head->nextNode = newNode;
    nodeCount++;
}

void LinkedList::add(int index, int data) {
    Node *newNode = new Node(data, head->nextNode);
    Node *curNode = head;
    for(int i=0; i<index; i++) {
        curNode = curNode->nextNode;
    }
    newNode->nextNode = curNode->nextNode;
    curNode->nextNode = newNode;
    nodeCount++;
}

void LinkedList::remove(int index) {
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

bool LinkedList::isEmpty(){
    return nodeCount==0;
}

int LinkedList::size() {
    return nodeCount;
}

#endif ALGORITHM_HUSTLE_LINKED_LIST_H
